/*-------------------------------------------------------------------------------------------
 * qblocks - fast, easily-accessible, fully-decentralized data from blockchains
 * copyright (c) 2018 Great Hill Corporation (http://greathill.com)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include <algorithm>
#include "reloadxid.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CReLoadXid, CTransaction);

//---------------------------------------------------------------------------
static string_q nextReloadxidChunk(const string_q& fieldIn, const void *dataPtr);
static string_q nextReloadxidChunk_custom(const string_q& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CReLoadXid::Format(ostream& ctx, const string_q& fmtIn, void *dataPtr) const {
    if (!m_showing)
        return;

    if (fmtIn.empty()) {
        ctx << toJson();
        return;
    }

    string_q fmt = fmtIn;
    // EXISTING_CODE
    // EXISTING_CODE

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextReloadxidChunk, this);
}

//---------------------------------------------------------------------------
string_q nextReloadxidChunk(const string_q& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return reinterpret_cast<const CReLoadXid *>(dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CReLoadXid::setValueByName(const string_q& fieldName, const string_q& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CTransaction::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_affCode" ) { _affCode = str_2_Wei(fieldValue); return true; }
            if ( fieldName % "_team" ) { _team = str_2_Wei(fieldValue); return true; }
            if ( fieldName % "_eth" ) { _eth = str_2_Wei(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CReLoadXid::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CReLoadXid::Serialize(CArchive& archive) {

    if (archive.isWriting())
        return SerializeC(archive);

    // Always read the base class (it will handle its own backLevels if any, then
    // read this object's back level (if any) or the current version.
    CTransaction::Serialize(archive);
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> _affCode;
    archive >> _team;
    archive >> _eth;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CReLoadXid::SerializeC(CArchive& archive) const {

    // Writing always write the latest version of the data
    CTransaction::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << _affCode;
    archive << _team;
    archive << _eth;

    return true;
}

//---------------------------------------------------------------------------
CArchive& operator>>(CArchive& archive, CReLoadXidArray& array) {
    uint64_t count;
    archive >> count;
    array.resize(count);
    for (size_t i = 0 ; i < count ; i++) {
        ASSERT(i < array.capacity());
        array.at(i).Serialize(archive);
    }
    return archive;
}

//---------------------------------------------------------------------------
CArchive& operator<<(CArchive& archive, const CReLoadXidArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0 ; i < array.size() ; i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void CReLoadXid::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CTransaction::registerClass();

    size_t fieldNum = 1000;
    ADD_FIELD(CReLoadXid, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CReLoadXid, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CReLoadXid, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CReLoadXid, "cname", T_TEXT,  ++fieldNum);
    ADD_FIELD(CReLoadXid, "_affCode", T_NUMBER, ++fieldNum);
    ADD_FIELD(CReLoadXid, "_team", T_NUMBER, ++fieldNum);
    ADD_FIELD(CReLoadXid, "_eth", T_NUMBER, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CReLoadXid, "schema");
    HIDE_FIELD(CReLoadXid, "deleted");
    HIDE_FIELD(CReLoadXid, "showing");
    HIDE_FIELD(CReLoadXid, "cname");

    builtIns.push_back(_biCReLoadXid);

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextReloadxidChunk_custom(const string_q& fieldIn, const void *dataPtr) {
    const CReLoadXid *rel = reinterpret_cast<const CReLoadXid *>(dataPtr);
    if (rel) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, rel);
                // EXISTING_CODE
                // EXISTING_CODE
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool CReLoadXid::readBackLevel(CArchive& archive) {

    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
string_q CReLoadXid::getValueByName(const string_q& fieldName) const {

    // Give customized code a chance to override first
    string_q ret = nextReloadxidChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_affCode" ) return bnu_2_Str(_affCode);
            if ( fieldName % "_team" ) return bnu_2_Str(_team);
            if ( fieldName % "_eth" ) return bnu_2_Str(_eth);
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CTransaction::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CReLoadXid& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    item.Format(os, "", nullptr);
    os << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE
