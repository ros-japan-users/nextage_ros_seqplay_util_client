nextage_ros_seqplay_util
========================

ROS package of SequencePlayer utility for NEXTAGE OPEN

近藤さんのROS勉強記第4回にあるサービスを端末から呼ぶサンプルをC++形式で書いたサービスクライアント(src/sample.cpp)です.

clientを生成するためにCmakeList.txtのbuildを編集しています。
参考:ROStutorial http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29


僕もわからないのです, goInitial, /goOffPose, /setTargetPoseRelativeのサービスは動作が成功していても
client.call(srv)がfalseを返してくるので、エラー処理を飛ばしています.

Build
-----

~~~ sh
$ cd /path/to/catkin_ws/src
$ git clone  https://github.com/NaohiroHayashi/nextage_ros_seqplay_util.git
$ cd ..
$ catkin_make
~~~


Execution
---------
**terminal #1**
~~~sh
$ roscore
~~~

**terminal #2**
~~~sh
$ rtmlaunch nextage_ros_bridge nextage_ros_bridge_simulation.launch
~~~

**terminal #3**
~~~sh
$ rosrun nextage_ros_seqplay_util seqplay_util_server.py
~~~

**terminal #4**
~~~sh
$ rosservice list /nextage_ros_seqplay_util
/nextage_ros_seqplay_util/get_loggers
/nextage_ros_seqplay_util/goInitial
/nextage_ros_seqplay_util/goOffPose
/nextage_ros_seqplay_util/setTargetPoseRelative
/nextage_ros_seqplay_util/set_logger_level
$ rosrun nextage_ros_seqplay_util sample
~~~
