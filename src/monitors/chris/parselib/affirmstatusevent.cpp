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
#include "affirmstatusevent.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CAffirmStatusEvent, CLogEntry);

//---------------------------------------------------------------------------
static string_q nextAffirmstatuseventChunk(const string_q& fieldIn, const void *dataPtr);
static string_q nextAffirmstatuseventChunk_custom(const string_q& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CAffirmStatusEvent::Format(ostream& ctx, const string_q& fmtIn, void *dataPtr) const {
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
        ctx << getNextChunk(fmt, nextAffirmstatuseventChunk, this);
}

//---------------------------------------------------------------------------
string_q nextAffirmstatuseventChunk(const string_q& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return reinterpret_cast<const CAffirmStatusEvent *>(dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CAffirmStatusEvent::setValueByName(const string_q& fieldName, const string_q& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CLogEntry::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_sender" ) { _sender = str_2_Addr(fieldValue); return true; }
            if ( fieldName % "_account" ) { _account = str_2_Addr(fieldValue); return true; }
            if ( fieldName % "_affirmDate" ) { _affirmDate = str_2_Wei(fieldValue); return true; }
            if ( fieldName % "_value" ) { _value = str_2_Wei(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CAffirmStatusEvent::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CAffirmStatusEvent::Serialize(CArchive& archive) {

    if (archive.isWriting())
        return SerializeC(archive);

    // Always read the base class (it will handle its own backLevels if any, then
    // read this object's back level (if any) or the current version.
    CLogEntry::Serialize(archive);
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> _sender;
    archive >> _account;
    archive >> _affirmDate;
    archive >> _value;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CAffirmStatusEvent::SerializeC(CArchive& archive) const {

    // Writing always write the latest version of the data
    CLogEntry::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << _sender;
    archive << _account;
    archive << _affirmDate;
    archive << _value;

    return true;
}

//---------------------------------------------------------------------------
CArchive& operator>>(CArchive& archive, CAffirmStatusEventArray& array) {
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
CArchive& operator<<(CArchive& archive, const CAffirmStatusEventArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0 ; i < array.size() ; i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void CAffirmStatusEvent::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CLogEntry::registerClass();

    size_t fieldNum = 1000;
    ADD_FIELD(CAffirmStatusEvent, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "cname", T_TEXT,  ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "_sender", T_ADDRESS, ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "_account", T_ADDRESS, ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "_affirmDate", T_NUMBER, ++fieldNum);
    ADD_FIELD(CAffirmStatusEvent, "_value", T_NUMBER, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CAffirmStatusEvent, "schema");
    HIDE_FIELD(CAffirmStatusEvent, "deleted");
    HIDE_FIELD(CAffirmStatusEvent, "showing");
    HIDE_FIELD(CAffirmStatusEvent, "cname");

    builtIns.push_back(_biCAffirmStatusEvent);

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextAffirmstatuseventChunk_custom(const string_q& fieldIn, const void *dataPtr) {
    const CAffirmStatusEvent *aff = reinterpret_cast<const CAffirmStatusEvent *>(dataPtr);
    if (aff) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, aff);
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
bool CAffirmStatusEvent::readBackLevel(CArchive& archive) {

    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
string_q CAffirmStatusEvent::getValueByName(const string_q& fieldName) const {

    // Give customized code a chance to override first
    string_q ret = nextAffirmstatuseventChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_sender" ) return addr_2_Str(_sender);
            if ( fieldName % "_account" ) return addr_2_Str(_account);
            if ( fieldName % "_affirmDate" ) return bnu_2_Str(_affirmDate);
            if ( fieldName % "_value" ) return bnu_2_Str(_value);
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CLogEntry::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CAffirmStatusEvent& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    item.Format(os, "", nullptr);
    os << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE
