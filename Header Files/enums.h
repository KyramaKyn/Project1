#pragma once
#include <iostream>
#include <string>

enum class InstitutionType { outpatient, medical_center, hospital, polyclinic };
enum class BedStatus { free, occupied };

std::ostream& operator<<(std::ostream& os, const InstitutionType& type);
std::ostream& operator<<(std::ostream& os, const BedStatus& status);