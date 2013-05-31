#include "testApp.h"


#define OMX_INIT_STRUCTURE(a) \
memset(&(a), 0, sizeof(a)); \
(a).nSize = sizeof(a); \
(a).nVersion.s.nVersionMajor = OMX_VERSION_MAJOR; \
(a).nVersion.s.nVersionMinor = OMX_VERSION_MINOR; \
(a).nVersion.s.nRevision = OMX_VERSION_REVISION; \
(a).nVersion.s.nStep = OMX_VERSION_STEP


void testApp::listRoles(char *name) {
    OMX_U32 numRoles;
	vector<OMX_U8*> roles;
    //get the number of roles by passing in a NULL roles param 
    OMX_ERRORTYPE err = OMX_GetRolesOfComponent(name, &numRoles, NULL);
    if (err != OMX_ErrorNone) 
	{
		ofLogVerbose() << "Getting roles failed";
		return;
    }
	ofLogVerbose() << "numRoles: " << numRoles;
	
    //now get the roles 
	
    for (int i = 0; i < numRoles; i++) 
	{
		unsigned char* role = new unsigned char[OMX_MAX_STRINGNAME_SIZE];
		roles.push_back(role);
    }
    err = OMX_GetRolesOfComponent(name, &numRoles, &roles[0]);
    if (err != OMX_ErrorNone) 
	{
		ofLogVerbose() << "OMX_GetRolesOfComponent FAIL";
		return;
    }
    for (int i = 0; i < roles.size(); i++) 
	{
		ofLogVerbose() << "role: " << roles[i];
    }
	
}
OMX_ERRORTYPE testApp::EventHandlerCallback(OMX_HANDLETYPE hComponent, OMX_PTR pAppData,
									  OMX_EVENTTYPE eEvent, OMX_U32 nData1, OMX_U32 nData2, OMX_PTR pEventData)
{
	//ofLogVerbose() << "EventHandlerCallback";
	
	ofLog(OF_LOG_VERBOSE, 
		  "testApp::%s - eEvent(0x%x), nData1(0x%lx), nData2(0x%lx), pEventData(0x%p)\n",
		  __func__, eEvent, nData1, nData2, pEventData);
	return OMX_ErrorNone;
}

OMX_ERRORTYPE testApp::cameraEventHandlerCallback(OMX_HANDLETYPE hComponent, OMX_PTR pAppData,
											OMX_EVENTTYPE eEvent, OMX_U32 nData1, OMX_U32 nData2, OMX_PTR pEventData)
{
	//ofLogVerbose() << "cameraEventHandlerCallback";
	ofLog(OF_LOG_VERBOSE, 
		  "testApp::%s - eEvent(0x%x), nData1(0x%lx), nData2(0x%lx), pEventData(0x%p)\n",
		  __func__, eEvent, nData1, nData2, pEventData);
	switch (eEvent) 
	{
		case OMX_EventCmdComplete:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventCmdComplete";
			break;
		}
		case OMX_EventError:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventError";
			break;
		}
		case OMX_EventMark:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventMark";
			break;
		}
		case OMX_EventPortSettingsChanged:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventPortSettingsChanged";
			break;
		}
		case OMX_EventBufferFlag:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventBufferFlag";
			break;
		}
		case OMX_EventResourcesAcquired:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventResourcesAcquired";
			break;
		}
		case OMX_EventComponentResumed:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventComponentResumed";
			break;
		}
		case OMX_EventDynamicResourcesAvailable:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventDynamicResourcesAvailable";
			break;
		}
		case OMX_EventPortFormatDetected:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventPortFormatDetected";
			break;
		}
		case OMX_EventKhronosExtensions:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventKhronosExtensions";
			break;
		}
		case OMX_EventVendorStartUnused:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventVendorStartUnused";
			break;
		}
		case OMX_EventParamOrConfigChanged:
		{
			
			ofLogVerbose() << __func__ <<  " OMX_EventParamOrConfigChanged";
			testApp *app = static_cast<testApp*>(pAppData);
			app->onCameraEventParamOrConfigChanged();
			
			
			break;
		}
		case OMX_EventMax:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventMax";
			break;
		}		
		default:
		{
			ofLogVerbose() << __func__ <<  "DEFAULT";
			break;
		}
			
	}
	//ofLogVerbose() << "END --- cameraEventHandlerCallback";
	return OMX_ErrorNone;
}

OMX_ERRORTYPE testApp::renderEventHandlerCallback(OMX_HANDLETYPE hComponent, OMX_PTR pAppData,
												  OMX_EVENTTYPE eEvent, OMX_U32 nData1, OMX_U32 nData2, OMX_PTR pEventData)
{
	//ofLogVerbose() << "renderEventHandlerCallback";
	ofLog(OF_LOG_VERBOSE, 
		  "testApp::%s - eEvent(0x%x), nData1(0x%lx), nData2(0x%lx), pEventData(0x%p)\n",
		  __func__, eEvent, nData1, nData2, pEventData);
	switch (eEvent) 
	{
		case OMX_EventCmdComplete:
		{
			ofLogVerbose() << __func__ << " OMX_EventCmdComplete";
			break;
		}
		case OMX_EventError:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventError";
			break;
		}
		case OMX_EventMark:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventMark";
			break;
		}
		case OMX_EventPortSettingsChanged:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventPortSettingsChanged";
			break;
		}
		case OMX_EventBufferFlag:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventBufferFlag";
			break;
		}
		case OMX_EventResourcesAcquired:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventResourcesAcquired";
			break;
		}
		case OMX_EventComponentResumed:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventComponentResumed";
			break;
		}
		case OMX_EventDynamicResourcesAvailable:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventDynamicResourcesAvailable";
			break;
		}
		case OMX_EventPortFormatDetected:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventPortFormatDetected";
			break;
		}
		case OMX_EventKhronosExtensions:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventKhronosExtensions";
			break;
		}
		case OMX_EventVendorStartUnused:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventVendorStartUnused";
			break;
		}
		case OMX_EventParamOrConfigChanged:
		{
			
			ofLogVerbose() << __func__ <<  " OMX_EventParamOrConfigChanged";			
			break;
		}
		case OMX_EventMax:
		{
			ofLogVerbose() << __func__ <<  " OMX_EventMax";
			break;
		}		
		default:
		{
			ofLogVerbose() << "DEFAULT";
			break;
		}
			
	}
	//ofLogVerbose() << "END --- renderEventHandlerCallback";
	return OMX_ErrorNone;
}

OMX_ERRORTYPE testApp::renderEmptyBufferDone(OMX_IN OMX_HANDLETYPE hComponent,
                                           OMX_IN OMX_PTR pAppData,
                                           OMX_IN OMX_BUFFERHEADERTYPE* pBuffer)
{
	ofLogVerbose() << "renderEmptyBufferDone";
	return OMX_ErrorNone;
}
OMX_ERRORTYPE testApp::renderFillBufferDone(OMX_IN OMX_HANDLETYPE hComponent,
                                          OMX_IN OMX_PTR pAppData,
                                          OMX_IN OMX_BUFFERHEADERTYPE* pBuffer)
{
	ofLogVerbose() << "renderFillBufferDone";

	return OMX_ErrorNone;
}

void testApp::onCameraEventParamOrConfigChanged()
{
	ofLogVerbose() << "onCameraEventParamOrConfigChanged";
	OMX_ERRORTYPE error = OMX_SendCommand(camera, OMX_CommandStateSet, OMX_StateIdle, NULL);
	if (error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SendCommand PASS";
	}else 
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SendCommand FAIL omx_err(0x%08x)\n", error);
	}
	
	OMX_CONFIG_PORTBOOLEANTYPE cameraport;
	OMX_INIT_STRUCTURE(cameraport);
	cameraport.nPortIndex = 71;
	cameraport.bEnabled = OMX_TRUE;
	error =OMX_SetParameter(camera, OMX_IndexConfigPortCapturing, &cameraport);	
	if (error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetParameter PASS";
	}else 
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetParameter FAIL omx_err(0x%08x)\n", error);
	}
	std::string componentName = "";
	componentName = "OMX.broadcom.egl_render";
	renderCallbacks.EventHandler    = &testApp::renderEventHandlerCallback;
	renderCallbacks.EmptyBufferDone = &testApp::renderEmptyBufferDone;
	renderCallbacks.FillBufferDone = &testApp::renderFillBufferDone;
	error = OMX_GetHandle(&render, (OMX_STRING)componentName.c_str(), this , &renderCallbacks);
	DisableAllPorts(&render);
	
}
//--------------------------------------------------------------
void testApp::setup()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	bcm_host_init();
	char name[OMX_MAX_STRINGNAME_SIZE];
	OMX_ERRORTYPE error = OMX_Init();
	if (error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "OMX_Init PASS";
	}
	
    for (int i = 0; OMX_ErrorNoMore != error; i++)
	{
		error = OMX_ComponentNameEnum(name, OMX_MAX_STRINGNAME_SIZE, i);
		if (OMX_ErrorNone == error) {
			ofLog(OF_LOG_VERBOSE, "Component is %s\n", name);
			listRoles(name);
		}
    }
		
	
	
	
	const std::string cameraComponentName = "OMX.broadcom.camera";
	cameraCallbacks.EventHandler    = &testApp::cameraEventHandlerCallback;
	
	error = OMX_GetHandle(&camera, (OMX_STRING)cameraComponentName.c_str(), this , &cameraCallbacks);
	
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_GetHandle PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_GetHandle FAIL omx_err(0x%08x)\n", error);
	}
	
	OMX_ERRORTYPE didDisable = DisableAllPorts(&camera);
	if(didDisable == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera didDisable PASS";
	}else 
	{
		ofLog(OF_LOG_ERROR, "camera didDisable FAIL omx_err(0x%08x)\n", didDisable);
	}
	
	OMX_CONFIG_REQUESTCALLBACKTYPE cameraCallback;
	OMX_INIT_STRUCTURE(cameraCallback);
	cameraCallback.nPortIndex=OMX_ALL;
	cameraCallback.nIndex=OMX_IndexParamCameraDeviceNumber;
	cameraCallback.bEnable = OMX_TRUE;
	
	error = OMX_SetConfig(camera, OMX_IndexConfigRequestCallback, &cameraCallback);
	
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigRequestCallback PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigRequestCallback FAIL omx_err(0x%08x)\n", error);
	}

	
	OMX_PARAM_U32TYPE device;
	OMX_INIT_STRUCTURE(device);
	device.nPortIndex = OMX_ALL;
	device.nU32 = 0;
	error =  OMX_SetParameter(camera, OMX_IndexParamCameraDeviceNumber, &device);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetParameter OMX_IndexParamCameraDeviceNumber PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetParameter OMX_IndexParamCameraDeviceNumber FAIL omx_err(0x%08x)\n", error);
	}
	
						  
	//Set the resolution
	OMX_PARAM_PORTDEFINITIONTYPE portdef;
	OMX_INIT_STRUCTURE(portdef);
	portdef.nPortIndex = 71;
	
	error = OMX_GetParameter(camera, OMX_IndexParamPortDefinition, &portdef);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_GetParameter OMX_IndexParamPortDefinition PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_GetParameter OMX_IndexParamPortDefinition FAIL omx_err(0x%08x)\n", error);
	}
	
	portdef.format.image.nFrameWidth = 640;
	portdef.format.image.nFrameHeight = 360;
	portdef.format.image.nStride = 640;
	error = OMX_SetParameter(camera, OMX_IndexParamPortDefinition, &portdef);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetParameter OMX_IndexParamPortDefinition PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetParameter OMX_IndexParamPortDefinition FAIL omx_err(0x%08x)\n", error);
	}
	
	
	//Set the framerate 
	OMX_CONFIG_FRAMERATETYPE framerate;
	OMX_INIT_STRUCTURE(framerate);
	framerate.nPortIndex = 71;
	framerate.xEncodeFramerate = 25 << 16; //Q16 format - 25fps
	error = OMX_SetConfig(camera, OMX_IndexConfigVideoFramerate, &framerate);
	
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigVideoFramerate PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigVideoFramerate FAIL omx_err(0x%08x)\n", error);
	}
	
	
	//Set the sharpness 
	OMX_CONFIG_SHARPNESSTYPE sharpness;
	OMX_INIT_STRUCTURE(sharpness);
	sharpness.nPortIndex = OMX_ALL;
	sharpness.nSharpness = -50; //-100 to 100 
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonSharpness, &sharpness);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonSharpness PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonSharpness FAIL omx_err(0x%08x)\n", error);
	}
	//Set the contrast 
	OMX_CONFIG_CONTRASTTYPE contrast;
	OMX_INIT_STRUCTURE(contrast);
	contrast.nPortIndex = OMX_ALL;
	contrast.nContrast = -10; //-100 to 100 
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonContrast, &contrast);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonContrast PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonContrast FAIL omx_err(0x%08x)\n", error);
	}
	
	//Set the brightness
	OMX_CONFIG_BRIGHTNESSTYPE brightness;
	OMX_INIT_STRUCTURE(brightness);
	brightness.nPortIndex = OMX_ALL;
	brightness.nBrightness = 50; //0 to 100 
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonBrightness, &brightness);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonBrightness PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonBrightness FAIL omx_err(0x%08x)\n", error);
	}
	
	//Set the saturation 
	OMX_CONFIG_SATURATIONTYPE saturation;
	OMX_INIT_STRUCTURE(saturation);
	saturation.nPortIndex = OMX_ALL;
	saturation.nSaturation = 0; //-100 to 100 
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonSaturation, &saturation);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonSaturation PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonSaturation FAIL omx_err(0x%08x)\n", error);
	}
	
	
	//Video stabilisation
	OMX_CONFIG_FRAMESTABTYPE framestab;
	OMX_INIT_STRUCTURE(framestab);
	framestab.nPortIndex = OMX_ALL;
	framestab.bStab = OMX_FALSE;
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonFrameStabilisation, &framestab);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonFrameStabilisation PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonFrameStabilisation FAIL omx_err(0x%08x)\n", error);
	}
	
	//Set EV compensation, ISO and metering mode
	OMX_CONFIG_EXPOSUREVALUETYPE exposurevalue;
	OMX_INIT_STRUCTURE(exposurevalue);
	exposurevalue.nPortIndex = OMX_ALL;
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonExposureValue, &exposurevalue);
	if(error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonExposureValue PASS";
	}else
	{
		ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonExposureValue FAIL omx_err(0x%08x)\n", error);
	}	 
		 
	ofLog(OF_LOG_VERBOSE, "nSensitivity=%d\n", exposurevalue.nSensitivity);
	
	exposurevalue.xEVCompensation = 0;  //Fixed point value stored as Q16 
	exposurevalue.nSensitivity = 100;	//< e.g. nSensitivity = 100 implies "ISO 100" 
	exposurevalue.bAutoSensitivity = OMX_FALSE;
	exposurevalue.eMetering = OMX_MeteringModeAverage; 
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonExposureValue, &exposurevalue);
	 if(error == OMX_ErrorNone) 
	 {
		 ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonExposureValue PASS";
	 }else
	 {
		 ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonExposureValue FAIL omx_err(0x%08x)\n", error);
	 }
		 
		 
	//Set exposure mode
	OMX_CONFIG_EXPOSURECONTROLTYPE exposure;
	OMX_INIT_STRUCTURE(exposure);
	exposure.nPortIndex = OMX_ALL;
	exposure.eExposureControl = OMX_ExposureControlAuto;
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonExposure, &exposure);
	if(error == OMX_ErrorNone) 
	{
	 ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonExposure PASS";
	}else
	{
	 ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonExposure FAIL omx_err(0x%08x)\n", error);
	}
		 
	//Set AWB mode 
	OMX_CONFIG_WHITEBALCONTROLTYPE awb;
	OMX_INIT_STRUCTURE(awb);
	awb.nPortIndex = OMX_ALL;
	awb.eWhiteBalControl = OMX_WhiteBalControlAuto;
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonWhiteBalance, &awb);

	if(error == OMX_ErrorNone) 
	{
	 ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonWhiteBalance PASS";
	}else
	{
	 ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonWhiteBalance FAIL omx_err(0x%08x)\n", error);
	}
	
	//Set image effect 
	OMX_CONFIG_IMAGEFILTERTYPE imagefilter;
	OMX_INIT_STRUCTURE(imagefilter);
	imagefilter.nPortIndex = OMX_ALL;
	imagefilter.eImageFilter = OMX_ImageFilterNone;
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonImageFilter, &imagefilter);
	if(error == OMX_ErrorNone) 
	{
	 ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonImageFilter PASS";
	}else
	{
	 ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonImageFilter FAIL omx_err(0x%08x)\n", error);
	}
	
	//Set colour effect 
	OMX_CONFIG_COLORENHANCEMENTTYPE colour;
	OMX_INIT_STRUCTURE(colour);
	colour.nPortIndex = OMX_ALL;
	colour.bColorEnhancement = OMX_FALSE;
	colour.nCustomizedU = 128;
	colour.nCustomizedV = 128;
	error = OMX_SetConfig(camera, OMX_IndexConfigCommonColorEnhancement, &colour);
	if(error == OMX_ErrorNone) 
	{
	 ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigCommonColorEnhancement PASS";
	}else
	{
	 ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigCommonColorEnhancement FAIL omx_err(0x%08x)\n", error);
	}
	
	//Turn off the LED - doesn't work! 
	OMX_CONFIG_PRIVACYINDICATORTYPE privacy;
	OMX_INIT_STRUCTURE(privacy);
	privacy.ePrivacyIndicatorMode = OMX_PrivacyIndicatorOff;
	error = OMX_SetConfig(camera, OMX_IndexConfigPrivacyIndicator, &privacy);
	if(error == OMX_ErrorNone) 
	{
	ofLogVerbose() << "camera OMX_SetConfig OMX_IndexConfigPrivacyIndicator PASS";
	}else
	{
	ofLog(OF_LOG_ERROR, "camera OMX_SetConfig OMX_IndexConfigPrivacyIndicator FAIL omx_err(0x%08x)\n", error);
	}	 

	
}
OMX_ERRORTYPE testApp::DisableAllPorts(OMX_HANDLETYPE* m_handle)
{
	
	OMX_ERRORTYPE omx_err = OMX_ErrorNone;
	
	
	OMX_INDEXTYPE idxTypes[] = {
		OMX_IndexParamAudioInit,
		OMX_IndexParamImageInit,
		OMX_IndexParamVideoInit, 
		OMX_IndexParamOtherInit
	};
	
	OMX_PORT_PARAM_TYPE ports;
	OMX_INIT_STRUCTURE(ports);
	
	int i;
	for(i=0; i < 4; i++)
	{
		omx_err = OMX_GetParameter(*m_handle, idxTypes[i], &ports);
		if(omx_err == OMX_ErrorNone) {
			
			uint32_t j;
			for(j=0; j<ports.nPorts; j++)
			{
				OMX_PARAM_PORTDEFINITIONTYPE portFormat;
				OMX_INIT_STRUCTURE(portFormat);
				portFormat.nPortIndex = ports.nStartPortNumber+j;
				
				omx_err = OMX_GetParameter(*m_handle, OMX_IndexParamPortDefinition, &portFormat);
				if(omx_err != OMX_ErrorNone)
				{
					if(portFormat.bEnabled == OMX_FALSE)
						continue;
				}
				
				omx_err = OMX_SendCommand(*m_handle, OMX_CommandPortDisable, ports.nStartPortNumber+j, NULL);
				if(omx_err != OMX_ErrorNone)
				{
					ofLog(OF_LOG_VERBOSE, "\nCOMXCoreComponent::DisableAllPorts - Error disable port %d on component %s omx_err(0x%08x)", 
						  (int)(ports.nStartPortNumber) + j, "m_componentName", (int)omx_err);
				}
			}
	
		}
	}
	
	
	return OMX_ErrorNone;
}

//--------------------------------------------------------------
void testApp::update()
{
	
}


//--------------------------------------------------------------
void testApp::draw(){
	}



void testApp::exit()
{
	OMX_ERRORTYPE error = OMX_Deinit();
	if (error == OMX_ErrorNone) 
	{
		ofLogVerbose() << "OMX_Deinit PASS";
	}
	bcm_host_deinit();
	
	
}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}


//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
