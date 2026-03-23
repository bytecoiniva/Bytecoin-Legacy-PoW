// Copyright (c) 2012-2018, The CryptoNote developers, The Bytecoin developers.
// Copyright (c) 2026, Bytecoin Legacy Developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include "CryptoNote.hpp"
#include "common/StringTools.hpp"
#include "p2p/P2pProtocolTypes.hpp"

#ifndef CRYPTONOTE_NAME
#define CRYPTONOTE_NAME "bytecoin-legacy"
#endif

namespace cn { namespace parameters {

// --- GENESIS Y NETWORK ID ---
// Nuevo Hexadecimal de Génesis para separar la red de la vieja Bytecoin
const char GENESIS_COINBASE_TX_HEX[] =
    "010a01ff0001ffffffffffff0f029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121013c086a48c15fb637a96991bc6d53caf77068b5ba6eeb3c82357228c49790584a";

// Cambiamos el ID de red para que los nodos viejos no intenten conectarse a nosotros
constexpr UUID BYTECOIN_NETWORK = common::pfh<UUID>("20260323-4c45-4741-4359-524556495641"); 

// Reseteamos todas las alturas de upgrade al bloque 1 para empezar con tecnología moderna
const Height UPGRADE_HEIGHT_V2                  = 1;
const Height UPGRADE_HEIGHT_V3                  = 1;
const Height UPGRADE_HEIGHT_V4                  = 1;
const Height KEY_IMAGE_SUBGROUP_CHECKING_HEIGHT = 1;

// Versiones de bloque (Amethyst / v4 como base)
const uint8_t BLOCK_VERSION_AMETHYST       = 4;
const uint8_t TRANSACTION_VERSION_AMETHYST = 4;
const size_t MINIMUM_ANONYMITY_AMETHYST = 3;

// --- EMISIÓN Y MONEDA ---
const Amount MONEY_SUPPLY            = std::numeric_limits<uint64_t>::max();
const unsigned EMISSION_SPEED_FACTOR = 16; // Un poco más rápido que el original (18) para premiar a los primeros mineros
static_assert(EMISSION_SPEED_FACTOR > 0 && EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t DISPLAY_DECIMAL_POINT = 8;
const Amount MIN_DUST_THRESHOLD    = 1000000;
const Amount MAX_DUST_THRESHOLD    = 30000000000000000;
const Amount SELF_DUST_THRESHOLD   = 1000;

// Prefijos de dirección (Legacy BCNL)
const uint64_t ADDRESS_BASE58_PREFIX          = 6;      
const uint64_t ADDRESS_BASE58_PREFIX_AMETHYST = 572238; 
const uint64_t SENDPROOF_BASE58_PREFIX        = 86762904402638;
const uint64_t VIEWONLYWALLET_BASE58_PREFIX   = 3904523549390;

const char BLOCKS_FILENAME[]       = "blocks.bin";
const char BLOCKINDEXES_FILENAME[] = "blockindexes.bin";

// --- DIFICULTAD Y RECOMPENSAS ---
const Timestamp DIFFICULTY_TARGET              = 120; // 2 minutos por bloque
const Height EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET;

const Difficulty MINIMUM_DIFFICULTY_V1 = 1;
const Difficulty MINIMUM_DIFFICULTY    = 1000; // Bajamos la dificultad inicial para que tus 590 KH/s vuelen

const Height DIFFICULTY_WINDOW = 720;
const Height DIFFICULTY_CUT    = 60;
const Height DIFFICULTY_LAG    = 15;

// --- VOTACIÓN DE UPGRADE ---
const Height UPGRADE_VOTING_PERCENT = 90;
const Height UPGRADE_VOTING_WINDOW  = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
const Height UPGRADE_WINDOW         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY * 7;

// --- LIMITES DE BLOQUE Y TIEMPO ---
const Timestamp BLOCK_FUTURE_TIME_LIMIT             = 60 * 60 * 2;
const Height BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1_3 = 60;
const Height BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW      = 59;
const Height MAX_BLOCK_NUMBER = 500000000;
const Height MINED_MONEY_UNLOCK_WINDOW = 10;

const size_t MAX_HEADER_SIZE         = 2048;
const size_t BLOCK_CAPACITY_VOTE_MIN = 100 * 1000;
const size_t BLOCK_CAPACITY_VOTE_MAX = 2000 * 1000;
const Height BLOCK_CAPACITY_VOTE_WINDOW = 11;

// --- PUERTOS P2P (MODIFICADOS PARA EVITAR CONFLICTOS) ---
const uint16_t P2P_DEFAULT_PORT        = 18080; // Puerto P2P Legacy
const uint16_t RPC_DEFAULT_PORT        = 18081; // Puerto RPC Legacy
const uint16_t WALLET_RPC_DEFAULT_PORT = 18070;

// --- NODOS SEMILLA Y CHECKPOINTS (LIMPIEZA TOTAL) ---
// Aquí pondrás la IP de tu servidor una vez que el nodo esté corriendo
const char *const SEED_NODES[] = {}; 
const char *const SEED_NODES_STAGENET[] = {};

// BORRAMOS los checkpoints viejos para que la red empiece de cero (Bloque 0)
constexpr const HardCheckpoint CHECKPOINTS[] = {};
constexpr const HardCheckpoint CHECKPOINTS_STAGENET[] = {};

// Claves públicas para checkpoints (Puedes cambiarlas luego si querés control centralizado)
constexpr PublicKey P2P_STAT_TRUSTED_PUBLIC_KEY =
    common::pfh<PublicKey>("E29507CA55455F37A3B783EE2C5123B8B6A34A0C5CAAE050922C6254161480C1");

constexpr PublicKey CHECKPOINT_PUBLIC_KEYS[] = {
    common::pfh<PublicKey>("b397e789ba603046d5750bbf490e1569f55dc9cf1f91edd2605d55d7bc3603fc")};
constexpr PublicKey CHECKPOINT_PUBLIC_KEYS_TESTNET[] = {};
constexpr PublicKey CHECKPOINT_PUBLIC_KEYS_STAGENET[] = {};

}} // namespace cn::parameters
