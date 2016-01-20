# Face Recognization with opencv
Automatically recognize face using opencv classes.

Go to faceRecognization_opencv/bin and run ONCE: 
```
source update_path 
```

Save images of each object in a folder in database/database_faces
Save the image you want to recognize in database/checking_objects
Run to write csv files:
```
update_csv_all 
```

Run to recognize the saved objects
```
reg_eigen 
```

- [ ] read many files in checking directory
- [ ] write list of dependencies in this file
- [ ] capture picture in webcam from terminal
- [ ] change thresholds to avoid returning wrong prediction when there's no one
