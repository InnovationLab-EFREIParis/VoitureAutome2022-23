Le fichier json peut être ouvert comme un dictionnaire python (et convertit en dataframe pour plus de facilité une fois que tu en auras compris la structure)

Il contient l'enregistrement de plusieurs informations pour 2 tours de pistes (+1 tours vides donc techniuquement 3). Les informations sont 'steering_command','lidar_range_image','speed_command','car_position'. 

Chacune de ces clés de dictionnaires contient une liste. Chaque élément de cette liste correspond à un tour. Chaque élémeent de cette sous liste correspond à un temps `t` pendant le tour.

Chose que tu pourrais faire:
- [ ] Afficher le film du lidar.
- [ ] Calculer [l'entropy](https://www.youtube.com/watch?v=0GCGaw0QOhA) des commandes ('steering_command' et 'speed_command').
- [ ] Afficher le film du lidar en prenant en compte la position de la voiture. 
- [ ] Comparer les deux tours.
- [ ] ...