/**
   These properties in AudioToolbox.h were renamed in macOS 12. In order to provide backwards compatibility for
   Xcode versions that are before v13, this creates duplicate properties of the future name. This file does
   nothing if you're working in Xcode 13+.
 */

#pragma once

#ifndef SimplyCoreAudio_h
#define SimplyCoreAudio_h

#include <Availability.h>
#import <AudioToolbox/AudioToolbox.h>

#ifdef __MAC_OS_X_VERSION_MAX_ALLOWED
#if __MAC_OS_X_VERSION_MAX_ALLOWED < 120000

CF_ENUM(AudioObjectPropertySelector)
{
	kAudioHardwareServiceDeviceProperty_VirtualMainVolume = kAudioHardwareServiceDeviceProperty_VirtualMasterVolume,
	kAudioHardwareServiceDeviceProperty_VirtualMainBalance = kAudioHardwareServiceDeviceProperty_VirtualMasterBalance
};

static AudioObjectPropertyScope kAudioObjectPropertyElementMain = kAudioObjectPropertyElementMaster;

#endif
#endif /* __MAC_OS_X_VERSION_MAX_ALLOWED */

#ifndef kAudioAggregateDeviceMainSubDeviceKey
#define kAudioAggregateDeviceMainSubDeviceKey "master"
#endif

// Catalyst doesn't have access to given properties but as they are defined as consts, we can get from documentation and update periodically
// https://developer.apple.com/documentation/audiotoolbox/1405208-audio_hardware_services_properti/kaudiohardwareservicedeviceproperty_virtualmainvolume?language=objc
// https://developer.apple.com/documentation/audiotoolbox/1405208-audio_hardware_services_properti/kaudiohardwareservicedeviceproperty_virtualmainbalance?language=objc
#if TARGET_OS_MACCATALYST
#import <CoreAudio/CoreAudio.h>

CF_ENUM(AudioObjectPropertySelector)
{
    kAudioHardwareServiceDeviceProperty_VirtualMainVolume = 'vmvc',
    kAudioHardwareServiceDeviceProperty_VirtualMainBalance = 'vmbc'
};

#endif

#endif /* SimplyCoreAudio_h */
