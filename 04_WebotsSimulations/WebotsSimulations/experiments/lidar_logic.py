import numpy as np

def main(self, lidar_scan):
    raw_lidar = np.array(lidar_scan.tolist())

    raw_lidar[~np.isfinite(raw_lidar)] = self.min_range





    filtered_lidar = np.array_split(raw_lidar,self.filter_resolution)

    filtered_lidar = [np.median(chunk) for chunk in filtered_lidar]
    angular_resolution_deg = 360 / len(filtered_lidar)
    angular_resolution_rad = 2 * np.pi / len(filtered_lidar)

    aperture = int(self.aperture_half_angle / angular_resolution_deg)

    lidar = filtered_lidar[-aperture:] + filtered_lidar[:aperture + 1]

    if self.sampling_step > 1:
        sampled_lidar = lidar[::self.sampling_step]
    else:
        sampled_lidar = lidar

    


if __name__ == "__main__":
    class dotdict(dict):
        """dot.notation access to dictionary attributes"""
        __getattr__ = dict.get
        __setattr__ = dict.__setitem__
        __delattr__ = dict.__delitem__

    self = {'sampling_step':2,'aperture_half_angle':75,'min_range':0.15,'filter_resolution':8}
    self = dotdict(self)

    lidar_scan = np.array([4,90,92,29,27,0,17,0,101,0,9,0,0,1,2,31,38,28,4])
    main(self,lidar_scan)