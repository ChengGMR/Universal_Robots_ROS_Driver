#include "ur_modern_driver/ur/messages.h"

bool MessageBase::parse_with(BinParser &bp) {
    bp.parse(timestamp);
    bp.parse(source);

    return true; //not really possible to check dynamic size packets
}


bool VersionMessage::parse_with(BinParser &bp) {
    
    bp.parse(project_name);
    bp.parse(major_version);
    bp.parse(minor_version);
    bp.parse(svn_version);
    bp.consume(sizeof(uint32_t)); //undocumented field??
    bp.parse_remainder(build_date);

    return true; //not really possible to check dynamic size packets    
}