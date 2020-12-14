mkdir weights

wget https://pjreddie.com/media/files/yolov3.weights -O ./weights/yolov3.weights
wget https://github.com/pjreddie/darknet/blob/master/cfg/yolov3.cfg?raw=true -O ./weights/yolov3.cfg
wget https://github.com/pjreddie/darknet/blob/master/data/coco.names?raw=true -O ./weights/coco.names
