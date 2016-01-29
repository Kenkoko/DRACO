# DRACO - Data Random Access and COllecting system
[![GitHub version](https://github.com/cer-nagas/DRACO/releases/tag/v0.1.1)](https://travis-ci.org/milligram/milligram)

## Synopsis
Use camera to collect image, detect and crop only faces, recognize each person
and save their images into a separate folder.
VERSION Lozenge

## Installation
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

## License
Copyright [2016] [Hoi "Nagas" Nguyen]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


- [ ] read many files in checking directory
- [ ] Use cvtColor() to convert images to grayscale
- [ ] Try to use resize() to resize all images
- [ ] change thresholds to avoid returning wrong prediction when there's no one
- [ ] write list of dependencies in this filec
- [ ] capture picture in webcam from terminal
- [ ] When database is big enough, recognize with different methods and make statistics. Statistics should be automated and updated continuously
