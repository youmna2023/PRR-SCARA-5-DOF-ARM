#!/usr/bin/env python3 import rospy
from std_msgs.msg import Int8
from std_msgs.msg import Bool


def stepper1UP_cb (msg):
	if msg.data == 1:
		stepper1UP=1
	else:
		stepper1UP=0
	pub.publish (stepper1UP)
	rate.sleep()
	rospy.loginfo(stepper1UP)


def stepper1DOWN_cb (msg):
	if msg.data == 1:
		stepper1DOWN=2
	else:
		stepper1DOWN=0
	pub.publish (stepper1DOWN)
	rate.sleep()
	rospy.loginfo(stepper1DOWN)


def stepper2RIGHT_cb (msg):
	if msg.data == 1:
		stepper2RIGHT=3
	else:
		stepper2RIGHT=0
	pub.publish (stepper2RIGHT)
	rate.sleep()
	rospy.loginfo(stepper2RIGHT)


def stepper2LEFT_cb (msg):
	if msg.data == 1:
		stepper2LEFT=4
	else:
		stepper2LEFT=0
	pub.publish (stepper2LEFT)
	rate.sleep()
	rospy.loginfo(stepper2LEFT)


def servo1RIGHT_cb (msg):
	if msg.data == 1:
		servo1RIGHT=5
	else:
		servo1RIGHT=0
	pub.publish (servo1RIGHT)
	rate.sleep()
	rospy.loginfo(servo1RIGHT)


def servo1LEFT_cb (msg):
	if msg.data == 1:
		servo1LEFT=6
	else:
		servo1LEFT=0
	pub.publish (servo1LEFT)
	rate.sleep()
	rospy.loginfo(servo1LEFT)


def servo2RIGHT_cb (msg):
	if msg.data == 1:
		servo2RIGHT=7
	else:
		servo2RIGHT=0
	pub.publish (servo2RIGHT)
	rate.sleep()
	rospy.loginfo(servo2RIGHT)


def servo2LEFT_cb (msg):
	if msg.data == 1:
		servo2LEFT=8
	else:
		servo2LEFT=0
	pub.publish (servo2LEFT)
	rate.sleep()
	rospy.loginfo(servo2LEFT)


def gripper1_cb (msg):
	if msg.data == True:
		gripper=9
	else:
		gripper=0
	pub.publish (gripper)
	rate.sleep()
	rospy.loginfo(gripper)

def gripper0_cb (msg):
	if msg.data == True:
		gripper=10
	else:
		gripper=0
	pub.publish (gripper)
	rate.sleep()
	rospy.loginfo(gripper)


def android():
	global pub
	rospy.init_node("android_app",anonymous=True)
	global rate
	rate = rospy.Rate(10)
	rospy.Subscriber("stepperup",Bool,stepper1UP_cb)
	rospy.Subscriber("stepperdown",Bool,stepper1DOWN_cb)
	rospy.Subscriber("stepperright",Bool,stepper2RIGHT_cb)
	rospy.Subscriber("stepperleft",Bool,stepper2LEFT_cb)
	rospy.Subscriber("servolright",Bool,servo1RIGHT_cb)
	rospy.Subscriber("servolleft",Bool,servo1LEFT_cb)
	rospy.Subscriber("servogright",Bool,servo2RIGHT_cb)
	rospy.Subscriber("servogleft",Bool,servo2LEFT_cb)
	rospy.Subscriber("gripperclose",Bool,gripper0_cb)
	rospy.Subscriber("gripperopen",Bool,gripper1_cb)
	pub=rospy.Publisher("android_topic" , Int8 , queue_size=1)  # publishing readings of joystick on topic "joy readings"
	rospy.spin()

if __name__ == '__main__':
	try:
		android()
	except rospy.ROSInterruptException:
		pass
