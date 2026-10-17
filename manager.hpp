#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "util.hpp"
#include <string>
#include <unordered_map>

struct PeerInfo {
    std::string ip;
    int mPort;
    int pPort;
    state peerState;
};

class Manager {
    private:
        std::unordered_map<std::string, PeerInfo> peerInfo;         // holds the information of all registered peers and their states
    public:
        Manager();   // default constructor

        // basics
        state getState(std::string peerName);
        void setState(std::string peerName, state newState);

        // communication with peers
        endStatus registerPeer(std::string peerName, std::string peerIP, int mPort, int pPort);
        endStatus setupDHT(std::string peerName, int n, int year);
        endStatus dhtComplete(std::string peerName);
        endStatus queryDHT(std::string peerName);
        endStatus leaveDHT(std::string peerName);
        endStatus joinDHT(std::string peerName);
        endStatus DHTrebuild(std::string peerName, std::string newLeaderName);
        endStatus deregisterPeer(std::string peerName);
        endStatus teardownDHT(std::string peerName);
        endStatus teardownComplete(std::string peerName);

};

#endif // MANAGER_HPP