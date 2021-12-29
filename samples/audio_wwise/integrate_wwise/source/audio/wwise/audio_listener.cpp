//
// Created by captain on 2021/8/5.
//

#include "audio_listener.h"
#include <rttr/registration>
#include "spdlog/spdlog.h"
#include "component/game_object.h"
#include "component/transform.h"

using namespace rttr;
RTTR_REGISTRATION
{
registration::class_<AudioListener>("AudioListener")
.constructor<>()(rttr::policy::ctor::as_raw_ptr);
}

AudioListener::AudioListener():Component() {

}

void AudioListener::Awake() {
    audio_listener_object_id_=WwiseAudio::GeneratorGameObjectID();
    WwiseAudio::CreateAudioObject(audio_listener_object_id_,"");
    WwiseAudio::SetDefaultListeners(audio_listener_object_id_);
}

void AudioListener::Update() {
    Component::Update();
    auto component_transform=game_object()->GetComponent("Transform");
    auto transform=dynamic_cast<Transform*>(component_transform);
    if(!transform){
        return;
    }
    auto pos=transform->position();
}