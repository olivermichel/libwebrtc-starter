
#include <iostream>
#include <api/peer_connection_interface.h>
#include <api/media_stream_interface.h>
#include <api/create_peerconnection_factory.h>


class WebRTCApplication 
    : public webrtc::PeerConnectionObserver,
      public webrtc::CreateSessionDescriptionObserver
{
public:
    rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface> factory;
    rtc::scoped_refptr<webrtc::PeerConnectionInterface> peer_connection;
    // rtc::scoped_refptr<MyVideoTrackSource> videoSource;
    // rtc::scoped_refptr<MyAudioSource> audioSource;
    // std::unique_ptr<VideoReceiver> videoReceiver;
    // std::unique_ptr<AudioReceiver> audioReceiver;

    void run() {
    
    }

    #pragma mark CreateSessionDescriptionObserver
    void OnSuccess(webrtc::SessionDescriptionInterface* desc) override {}
    void OnFailure(webrtc::RTCError error) override {}

    #pragma mark PeerConnectionObserver

    void OnAddTrack(
        rtc::scoped_refptr<webrtc::RtpReceiverInterface> receiver,
        const std::vector<rtc::scoped_refptr<webrtc::MediaStreamInterface>> &streams
    ) override {}
    void OnIceCandidate(const webrtc::IceCandidateInterface *candidate) override {}
    void OnConnectionChange(webrtc::PeerConnectionInterface::PeerConnectionState new_state) override {}
    void OnSignalingChange(webrtc::PeerConnectionInterface::SignalingState new_state) override {}
    void OnTrack(rtc::scoped_refptr<webrtc::RtpTransceiverInterface> transceiver) override {}
    void OnRemoveTrack(rtc::scoped_refptr<webrtc::RtpReceiverInterface> receiver) override {}
    void OnDataChannel(rtc::scoped_refptr<webrtc::DataChannelInterface> channel) override {}
    void OnRenegotiationNeeded() override {}
    void OnIceConnectionChange(webrtc::PeerConnectionInterface::IceConnectionState new_state) override {}
    void OnIceGatheringChange(webrtc::PeerConnectionInterface::IceGatheringState new_state) override {}
    void OnIceConnectionReceivingChange(bool receiving) override {}
    void OnStandardizedIceConnectionChange(
        webrtc::PeerConnectionInterface::IceConnectionState new_state) override {}
    void OnIceCandidateError(const std::string& address, int port, const std::string& url, 
        int error_code, const std::string& error_text) override {}
};

int main() {

    auto app = rtc::make_ref_counted<WebRTCApplication>();
    app->run();
    return 0;
}