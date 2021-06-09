include_directories (${CMAKE_SOURCE_DIR} wallet-core/include ${WALLET_CORE}/src ${WALLET_CORE}/build/local/include)
link_directories (wallet-core/build ${WALLET_CORE}/build/trezor-crypto ${WALLET_CORE}/build/local/lib)

find_library(WALLET_CORE_LIB_FILE TrustWalletCore PATH wallet-core/build)
if (NOT WALLET_CORE_LIB_FILE)
    message (FATAL_ERROR "TrustWalletCore library not found.  ${SETUP_MESSAGE}")
else ()
    message ("TrustWalletCore library found here: ${WALLET_CORE_LIB_FILE}")
endif ()
