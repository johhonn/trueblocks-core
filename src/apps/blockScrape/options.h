#pragma once
/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved.
 *------------------------------------------------------------------------*/
#include "acctlib.h"
#include "scraper_context.h"

//-----------------------------------------------------------------------------
class COptions : public COptionsBase {
public:
    blknum_t    startBlock;
    blknum_t    endBlock;
    blknum_t    maxBlocks;
    timestamp_t latestBlockTs;
    uint64_t    maxIndexRows;
    bool        writeBlocks;

    COptions(void);
    ~COptions(void);

    bool parseArguments(string_q& command);
    void Init(void);
};

//-------------------------------------------------------------------------
extern bool handle_scrape(COptions &options);
#define indexFolder_sorted    (getCachePath("addr_index/sorted/"))
