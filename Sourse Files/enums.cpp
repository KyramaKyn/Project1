#include "enums.h"

using namespace std;

ostream& operator<<(ostream& os, const InstitutionType& type) {
    switch (type) {
    case InstitutionType::outpatient:
        return os << "амбулаторія";
    case InstitutionType::medical_center:
        return os << "медичний центр";
    case InstitutionType::hospital:
        return os << "лікарня";
    case InstitutionType::polyclinic:
        return os << "поліклініка";
    default:
        return os << "невідомо";
    }
}

ostream& operator<<(ostream& os, const BedStatus& status) {
    switch (status) {
    case BedStatus::free:
        return os << "вільне";
    case BedStatus::occupied:
        return os << "зайняте";
    default:
        return os << "невідомо";
    }
}