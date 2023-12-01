import tkinter as tk
import rclpy
from std_msgs.msg import Bool
from interfaces.msg import ClientCommand
from interfaces.msg import RaceParams
import keyboard

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()

        self.node = rclpy.create_node('app_node')
        self.publisher_race = self.node.create_publisher(Bool, 'IsAppRaceOn', 1)
        self.publisher_params = self.node.create_publisher(RaceParams, 'RaceParams', 1)
        self.subscriber_race = self.node.create_subscription(Bool, 'IsRaceOn', self.getMessageRace, 1)
        self.subscriber_race = self.node.create_subscription(Bool, 'IsConnected', self.getMessageConnected, 1)

        self.publisher_manual = self.node.create_publisher(ClientCommand, 'ClientCommand', 1)

        self.topics = {
            'IsRaceOn': tk.Label(self, text='IsRaceOn: ', fg='red'),
            'IsConnected': tk.Label(self, text='IsConnected: ', fg='red'),
        }

        for topic_label in self.topics.values():
            topic_label.pack(side='left')

    def create_widgets(self):
        self.race_on_button = tk.Button(self)
        self.race_on_button["text"] = "Race on"
        self.race_on_button["command"] = self.race_on
        self.race_on_button.pack(side="left")

        self.race_off_button = tk.Button(self)
        self.race_off_button["text"] = "Race off"
        self.race_off_button["command"] = self.race_off
        self.race_off_button.pack(side="left")

        self.manual_control_button = tk.Button(self)
        self.manual_control_button["text"] = "Manual Control"
        self.manual_control_button["command"] = self.manual_control
        self.manual_control_button.pack(side="left")

        # Capture keyboard events using keyboard library
        keyboard.on_press_key('up', self.keyboard_input, suppress=True)
        keyboard.on_release_key('up', self.keyboard_input, suppress=True)
        keyboard.on_press_key('down', self.keyboard_input, suppress=True)
        keyboard.on_release_key('down', self.keyboard_input, suppress=True)
        keyboard.on_press_key('left', self.keyboard_input, suppress=True)
        keyboard.on_release_key('left', self.keyboard_input, suppress=True)
        keyboard.on_press_key('right', self.keyboard_input, suppress=True)
        keyboard.on_release_key('right', self.keyboard_input, suppress=True)

        # Add vertical scales
        self.speed_scale = tk.Scale(self, from_=10, to=0, orient=tk.VERTICAL, label="Speed")
        self.speed_scale.pack(side="left")

        self.steering_scale = tk.Scale(self, from_=10, to=0, orient=tk.VERTICAL, label="Steering")
        self.steering_scale.pack(side="left")

        self.send_params_button = tk.Button(self)
        self.send_params_button["text"] = "Update params"
        self.send_params_button["command"] = self.update_params
        self.send_params_button.pack(side="left")

    def update_params(self):
        params = RaceParams()
        params.speed = self.speed_scale.get()
        params.steering = self.steering_scale.get()
        self.publisher_params.publish(params)

    def race_on(self):
        print("Race on")
        msg = Bool()
        msg.data = True
        self.publisher_race.publish(msg)

    def race_off(self):
        print("Race off")
        msg = Bool()
        msg.data = False
        self.publisher_race.publish(msg)

    def manual_control(self):
        print("Manual Control")

    def getMessageRace(self, msg):
        self.topics['IsRaceOn']['fg'] = 'green' if msg.data else 'red'

    def getMessageConnected(self, msg):
        self.topics['IsConnected']['fg'] = 'green' if msg.data else 'red'

    def keyboard_input(self, event):
        message = ClientCommand()
        message.up = keyboard.is_pressed('up')
        message.down = keyboard.is_pressed('down')
        message.right = keyboard.is_pressed('right')
        message.left = keyboard.is_pressed('left')

        # Log the currently pressed keys
        pressed_keys = [key for key in ['up', 'down', 'right', 'left'] if keyboard.is_pressed(key)]
        self.node.get_logger().info(f"Keyboard input: {pressed_keys}")

        self.publisher_manual.publish(message)




def main(args=None):
    rclpy.init(args=args)

    root = tk.Tk()
    root.title("Fast and curious")
    app = Application(master=root)
    app.mainloop()


if __name__ == '__main__':
    main()
