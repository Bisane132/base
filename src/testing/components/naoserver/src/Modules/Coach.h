/**
 * @author fmartin
 *
 * Version : $Id$
 * This file was generated by Aldebaran Robotics ModuleGenerator
 */

#ifndef Coach_H
#define Coach_H


#include "alcore/alptr.h"
#include "alproxies/alledsproxy.h"
#include "alproxies/almemoryproxy.h"
#include "alproxies/alsensorsproxy.h"
#include "alproxies/alsonarproxy.h"
#include "alproxies/alrobotposeproxy.h"
#include "alcommon/alproxy.h"
#include "alcommon/albroker.h"

#include "Component.h"
#include "Body.h"
#include "Perception.h"
#include "Head.h"
#include "FSR.h"
#include "Kinematics.h"
#include "Kick.h"
#include "NaoServerCamera.h"
#include "NaoServerMotors.h"
#include "NaoServerEncoders.h"
#include "NaoServerPose3DMotors.h"
#include "NaoServerPose3DEncoders.h"
#include "SensorRecorderNao.h"

#include "CascadeScheduler.h"

#include <pthread.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

#include <IceE/IceE.h>
#include <image.h>

using namespace std;
using namespace jderobot;

namespace AL
{
class ALBroker;
}

using namespace AL;


#define Coach_VERSION_MAJOR "0"
#define Coach_VERSION_MINOR "0"

class Coach : public AL::ALModule
{

public:

	Coach(AL::ALPtr<AL::ALBroker> pBroker, const std::string& pName );
	virtual ~Coach();

private:

	static void* iceServerThread(void *obj);	//Ice

	Body	 	*body;
	Head 		*head;
	Perception	*perception;
	FSR			*fsr;
	CascadeScheduler *csched;
	Kinematics 	*kinematics;
	Kick	 *kick;
	NaoServerCamera	*servercamera;
	NaoServerMotors	*servermotors;
	NaoServerEncoders	*serverencoders;
	NaoServerPose3DMotors	*serverpose3dmotors;
	NaoServerPose3DEncoders	*serverpose3dencoders;
	SensorRecorderNao	*sensorrecordernao;

	AL::ALPtr<AL::ALProxy> psentinel;
	ALRobotPoseProxy *palrobotpose;
	ALSensorsProxy *psensors;
	ALSonarProxy *psonar;

	pthread_t tIceServer;

	int myIcePort;

};
#endif // Coach_H