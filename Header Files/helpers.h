#pragma once
#include "classes.h"
#include <string>
#include <vector>

int safe_stoi(const std::string& s, const std::string& context = "");
double safe_stod(const std::string& s, const std::string& context = "");
InstitutionType parseInstitutionType(const std::string& typeStr);
BedStatus parseBedStatus(const std::string& statusStr);
std::tm parseDate(const std::string& dateStr);
std::tm parseTime(const std::string& timeStr);
std::string
getDoctorFullName(int doctorId,
    const std::vector<std::shared_ptr<Doctor>>& doctors);
bool hasAcademicTitle(const std::string& degree);
bool isDateInRange(const std::tm& dateToCheck, const std::tm& startDate,
    const std::tm& endDate);
int daysBetween(const std::tm& start, const std::tm& end);
std::tm getDateFromUser();
bool validateHeader(const std::string& line,
    const std::vector<std::string>& expected);