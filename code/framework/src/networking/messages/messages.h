#pragma once

#include <BitStream.h>
#include <MessageIdentifiers.h>
#include <functional>

namespace Framework::Networking::Messages {
    using MessageCallback          = std::function<void(SLNet::BitStream *)>;
    using PacketCallback           = std::function<void(SLNet::Packet *)>;
    using DisconnectPacketCallback = std::function<void(SLNet::Packet *, uint32_t reason)>;

    enum DisconnectionReason { NO_FREE_SLOT, GRACEFUL_SHUTDOWN, LOST, FAILED, INVALID_PASSWORD, BANNED, UNKNOWN };

    enum GameMessages : uint32_t {
        GAME_CONNECTION_HANDSHAKE = ID_USER_PACKET_ENUM + 1,
        GAME_CONNECTION_FINALIZED,
        GAME_SYNC
    };

    enum GameSyncMessages : uint32_t {
        GAME_SYNC_PLAYER_SPAWN,
        GAME_SYNC_PLAYER_DESPAWN,
        GAME_SYNC_PLAYER_SET_POSITION,

        GAME_SYNC_VEHICLE_SPAWN,
        GAME_SYNC_VEHICLE_DESPAWN,
        GAME_SYNC_VEHICLE_SET_POSITION,

        // Used by mods to define custom mod-specific messages, e.g. (MOD_SYNC_FOO = GAME_SYNC_USER_PAKET_ENUM + 1)
        GAME_SYNC_USER_PACKET_ENUM,
    };
} // namespace Framework::Networking::Messages
