#ifndef PEER_HPP
#define PEER_HPP

#include "util.hpp"
#include <string>

class Peer {
    private:
        state peerState;

    public:
        Peer();   // default constructor
        Peer(state initialState);

        // basics
        state getState();
        void setState(state newState);

        // communication with manager
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

        // communication with other peers

};


#endif // PEER_HPP