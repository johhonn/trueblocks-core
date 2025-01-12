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
#include "parameter.h"

namespace qblocks {

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CParameter, CBaseNode);

//---------------------------------------------------------------------------
static string_q nextParameterChunk(const string_q& fieldIn, const void *dataPtr);
static string_q nextParameterChunk_custom(const string_q& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CParameter::Format(ostream& ctx, const string_q& fmtIn, void *dataPtr) const {
    if (!m_showing)
        return;

    string_q fmt = (fmtIn.empty() ? expContext().fmtMap["parameter_fmt"] : fmtIn);
    if (fmt.empty()) {
        ctx << toJson();
        return;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextParameterChunk, this);
}

//---------------------------------------------------------------------------
string_q nextParameterChunk(const string_q& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return reinterpret_cast<const CParameter *>(dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CParameter::setValueByName(const string_q& fieldNameIn, const string_q& fieldValueIn) {
    string_q fieldName = fieldNameIn;
    string_q fieldValue = fieldValueIn;

    // EXISTING_CODE
    // EXISTING_CODE

    switch (tolower(fieldName[0])) {
        case 'i':
            if ( fieldName % "indexed" ) { indexed = str_2_Bool(fieldValue); return true; }
            if ( fieldName % "isPointer" ) { isPointer = str_2_Bool(fieldValue); return true; }
            if ( fieldName % "isArray" ) { isArray = str_2_Bool(fieldValue); return true; }
            if ( fieldName % "isObject" ) { isObject = str_2_Bool(fieldValue); return true; }
            break;
        case 'n':
            if ( fieldName % "name" ) { name = fieldValue; return true; }
            break;
        case 's':
            if ( fieldName % "strDefault" ) { strDefault = fieldValue; return true; }
            break;
        case 't':
            if ( fieldName % "type" ) { type = fieldValue; return true; }
            break;
        case 'v':
            if ( fieldName % "value" ) { value = fieldValue; return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CParameter::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CParameter::Serialize(CArchive& archive) {

    if (archive.isWriting())
        return SerializeC(archive);

    // Always read the base class (it will handle its own backLevels if any, then
    // read this object's back level (if any) or the current version.
    CBaseNode::Serialize(archive);
    if (readBackLevel(archive))
        return true;

    // EXISTING_CODE
    // EXISTING_CODE
    archive >> indexed;
    archive >> name;
    archive >> type;
    archive >> isPointer;
    archive >> isArray;
    archive >> isObject;
    archive >> strDefault;
    archive >> value;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CParameter::SerializeC(CArchive& archive) const {

    // Writing always write the latest version of the data
    CBaseNode::SerializeC(archive);

    // EXISTING_CODE
    // EXISTING_CODE
    archive << indexed;
    archive << name;
    archive << type;
    archive << isPointer;
    archive << isArray;
    archive << isObject;
    archive << strDefault;
    archive << value;

    return true;
}

//---------------------------------------------------------------------------
CArchive& operator>>(CArchive& archive, CParameterArray& array) {
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
CArchive& operator<<(CArchive& archive, const CParameterArray& array) {
    uint64_t count = array.size();
    archive << count;
    for (size_t i = 0 ; i < array.size() ; i++)
        array[i].SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
void CParameter::registerClass(void) {
    // only do this once
    if (HAS_FIELD(CParameter, "schema")) return;

    size_t fieldNum = 1000;
    ADD_FIELD(CParameter, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CParameter, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CParameter, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CParameter, "cname", T_TEXT,  ++fieldNum);
    ADD_FIELD(CParameter, "indexed", T_BOOL, ++fieldNum);
    ADD_FIELD(CParameter, "name", T_TEXT, ++fieldNum);
    ADD_FIELD(CParameter, "type", T_TEXT, ++fieldNum);
    ADD_FIELD(CParameter, "isPointer", T_BOOL, ++fieldNum);
    ADD_FIELD(CParameter, "isArray", T_BOOL, ++fieldNum);
    ADD_FIELD(CParameter, "isObject", T_BOOL, ++fieldNum);
    ADD_FIELD(CParameter, "strDefault", T_TEXT, ++fieldNum);
    ADD_FIELD(CParameter, "value", T_TEXT, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CParameter, "schema");
    HIDE_FIELD(CParameter, "deleted");
    HIDE_FIELD(CParameter, "showing");
    HIDE_FIELD(CParameter, "cname");

    builtIns.push_back(_biCParameter);

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
string_q nextParameterChunk_custom(const string_q& fieldIn, const void *dataPtr) {
    const CParameter *par = reinterpret_cast<const CParameter *>(dataPtr);
    if (par) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, par);
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
bool CParameter::readBackLevel(CArchive& archive) {

    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
string_q CParameter::getValueByName(const string_q& fieldName) const {

    // Give customized code a chance to override first
    string_q ret = nextParameterChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // Return field values
    switch (tolower(fieldName[0])) {
        case 'i':
            if ( fieldName % "indexed" ) return bool_2_Str_t(indexed);
            if ( fieldName % "isPointer" ) return bool_2_Str_t(isPointer);
            if ( fieldName % "isArray" ) return bool_2_Str_t(isArray);
            if ( fieldName % "isObject" ) return bool_2_Str_t(isObject);
            break;
        case 'n':
            if ( fieldName % "name" ) return name;
            break;
        case 's':
            if ( fieldName % "strDefault" ) return strDefault;
            break;
        case 't':
            if ( fieldName % "type" ) return type;
            break;
        case 'v':
            if ( fieldName % "value" ) return value;
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CBaseNode::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CParameter& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    item.Format(os, "", nullptr);
    os << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
//---------------------------------------------------------------------------
CParameter::CParameter(string_q& textIn) {
    initialize();
    if (contains(textIn, "nowrite")) {
        noWrite = true;
        replace(textIn," (nowrite)","");
    }
    if (contains(textIn, "=")) {
        strDefault = textIn;
        textIn = nextTokenClear(strDefault, '=');
    }
    type       = nextTokenClear(textIn, ' ');
    isPointer  = contains(textIn, "*");
    isArray    = contains(textIn, "Array");
    isObject   = !isArray && startsWith(type, 'C');
    name       = substitute(textIn, "*", "");
}

//-----------------------------------------------------------------------
CParameter::CParameter(const string_q& n, const string_q& t, const string_q& v) {
    initialize();
    name = n;
    type = t;
    value = v;
}

//-----------------------------------------------------------------------
CParameter::CParameter(const string_q& n, const string_q& t, uint64_t v) {
    initialize();
    name = n;
    type = t;
    value = uint_2_Str(v);
}

//-----------------------------------------------------------------------
CParameter::CParameter(const string_q& n, const string_q& t, int64_t v) {
    initialize();
    name = n;
    type = t;
    value = int_2_Str(v);
}

//-----------------------------------------------------------------------
CParameter::CParameter(const string_q& n, const string_q& t, bool v) {
    initialize();
    name = n;
    type = t;
    value = bool_2_Str(v);
}

//-----------------------------------------------------------------------
CParameter::CParameter(const string_q& n, const string_q& t, biguint_t v) {
    initialize();
    name = n;
    type = t;
    value = bnu_2_Str(v);
}

//-----------------------------------------------------------------------
CParameter::CParameter(const string_q& n, const string_q& t, const CStringArray& array) {
    initialize();
    name = n;
    type = t;
    for (auto s : array)
        value += (s + "|");
}

//-----------------------------------------------------------------------
string_q CParameter::getFunctionAssign(uint64_t which) const {

    string_q ass;
    if (contains(type, "[") && contains(type, "]")) {
        const char* STR_ASSIGNARRAY =
            "\t\t\twhile (!params.empty()) {\n"
            "\t\t\t\tstring_q val = extract(params, 0, 64);\n"
            "\t\t\t\tparams = extract(params, 64);\n"
//            "\t\t\t\tif (contains(type,\"int\"))\n"
//            "\t\t\t\t\ta->[{NAME}].push_back(str_2_BigUint(val));\n"
//            "\t\t\t\telse\n"
//            "\t\t\t\t\ta->[{NAME}].push_back(val);\n"
            "\t\t\t\ta->[{NAME}].push_back(val);\n"
            "\t\t\t}\n";
        return Format(STR_ASSIGNARRAY);
    }

           if (         type == "uint")    { ass = "str_2_Wei(\"0x\" + [{VAL}]);";
    } else if (         type == "uint256") { ass = "str_2_Wei(\"0x\" + [{VAL}]);";
    } else if (contains(type, "gas"))      { ass = "str_2_Gas([{VAL}]);";
    } else if (contains(type, "uint64"))   { ass = "str_2_Uint([{VAL}]);";
    } else if (contains(type, "uint"))     { ass = "(uint32_t)str_2_Uint([{VAL}]);";
    } else if (contains(type, "int"))      { ass = "str_2_Int([{VAL}]);";
    } else if (contains(type, "bool"))     { ass = "str_2_Int([{VAL}]);";
    } else if (contains(type, "address"))  { ass = "str_2_Addr([{VAL}]);";
    } else                                 { ass = "[{VAL}];";
    }

    replace(ass, "[{VAL}]", "extract(params, " + uint_2_Str(which) + "*64" + (type == "bytes" ? "" : ", 64") + ")");
    return Format("\t\t\ta->[{NAME}] = " + ass + "\n");
}

//-----------------------------------------------------------------------
string_q CParameter::getEventAssign(uint64_t which, uint64_t nIndexed) const {
    string_q ass;

           if (         type == "uint")    { ass = "str_2_Wei([{VAL}]);";
    } else if (         type == "uint256") { ass = "str_2_Wei([{VAL}]);";
    } else if (contains(type, "gas"))      { ass = "str_2_Gas([{VAL}]);";
    } else if (contains(type, "uint64"))   { ass = "str_2_Uint([{VAL}]);";
    } else if (contains(type, "uint"))     { ass = "(uint32_t)str_2_Uint([{VAL}]);";
    } else if (contains(type, "int"))      { ass = "str_2_Int([{VAL}]);";
    } else if (contains(type, "bool"))     { ass = "str_2_Int([{VAL}]);";
    } else if (contains(type, "address"))  { ass = "str_2_Addr([{VAL}]);";
    } else                                 { ass = "[{VAL}];";
    }

    if (indexed) {
        replace(ass, "[{VAL}]", "nTops > [{WHICH}] ? topic_2_Str(p->topics[{IDX}]) : \"\"");

    } else if (type == "bytes") {
        replace(ass, "[{VAL}]", "\"0x\" + extract(data, [{WHICH}]*64)");
        which -= (nIndexed+1);

    } else {
        replace(ass, "[{VAL}]", string_q(type == "address" ? "" : "\"0x\" + ") + "extract(data, [{WHICH}]*64, 64)");
        which -= (nIndexed+1);
    }

    replace(ass, "[{IDX}]", "++" + uint_2_Str(which) + "++");
    replace(ass, "[{WHICH}]", uint_2_Str(which));
    string_q fmt = "\t\t\ta->[{NAME}] = " + ass + "\n";
    return Format(fmt);
}

//-----------------------------------------------------------------------
static string_q elementaryName(const string_q& in) {
    if (startsWith(in, "int["))    return "int256" + in.substr(3);
    if (in == "int")               return "int256";
    if (startsWith(in, "uint["))   return "uint256" + in.substr(4);
    if (in == "uint")              return "uint256";
    if (startsWith(in, "fixed["))  return "fixed128x128" + in.substr(5);
    if (in == "fixed")             return "fixed128x128";
    if (startsWith(in, "ufixed[")) return "ufixed128x128" + in.substr(6);
    if (in == "ufixed")            return "ufixed128x128";
    return in;
}

//-----------------------------------------------------------------------
bool CParameter::fromDefinition(const string_q &strIn) {
    string_q str = strIn;
    indexed = contains(str, "indexed");
    str = trim(substitute(str, "indexed ", ""));  // should be of form 'type name'
    type = elementaryName(nextTokenClear(str, ' '));
    isArray = contains(type, '[');
    name = str;
    return true;
}

//-----------------------------------------------------------------------
bool CParameter::isValid(void) const {
    // TODO(tjayrush): not exhaustive
    if (!(startsWith(type, "address") || startsWith(type, "bool") || startsWith(type, "string") || startsWith(type, "bytes") ||
          startsWith(type, "fixed") || startsWith(type, "uint")  || startsWith(type, "int")))
        return false;
    if (startsWith(type, "bytes") && type != "bytes") {
        uint64_t n = str_2_Uint(substitute(type,"bytes",""));
        return n > 0 && n <= 32;
    }
    return true;
}
// EXISTING_CODE
}  // namespace qblocks

