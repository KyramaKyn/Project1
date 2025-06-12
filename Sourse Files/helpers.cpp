#include "helpers.h"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

int safe_stoi(const std::string& s, const std::string& context) {
    try {
        return std::stoi(s);
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка конвертації '" << s << "' до числа";
        if (!context.empty())
            std::cerr << " в " << context;
        std::cerr << ". Використовую 0.\n";
        return 0;
    }
}

double safe_stod(const std::string& s, const std::string& context) {
    try {
        return std::stod(s);
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка конвертації '" << s << "' до дробового числа";
        if (!context.empty())
            std::cerr << " в " << context;
        std::cerr << ". Використовую 0.0.\n";
        return 0.0;
    }
}

InstitutionType parseInstitutionType(const std::string& typeStr) {
    if (typeStr == "амбулаторія")
        return InstitutionType::outpatient;
    if (typeStr == "медичний_центр")
        return InstitutionType::medical_center;
    if (typeStr == "лікарня")
        return InstitutionType::hospital;
    if (typeStr == "поліклініка")
        return InstitutionType::polyclinic;
    return InstitutionType::outpatient;
}

BedStatus parseBedStatus(const std::string& statusStr) {
    if (statusStr == "вільне")
        return BedStatus::free;
    if (statusStr == "зайняте")
        return BedStatus::occupied;
    return BedStatus::free;
}

std::tm parseDate(const std::string& dateStr) {
    std::tm t{};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&t, "%Y-%m-%d");
    if (ss.fail()) {
        std::cerr << "Помилка розбору дати: " << dateStr << std::endl;
        return std::tm{};
    }
    return t;
}

std::tm parseTime(const std::string& timeStr) {
    std::tm t{};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&t, "%H:%M");
    if (ss.fail()) {
        std::cerr << "Помилка розбору часу: " << timeStr << std::endl;
        return std::tm{};
    }
    return t;
}

std::string
getDoctorFullName(int doctorId,
    const std::vector<std::shared_ptr<Doctor>>& doctors) {
    for (const auto& doctor : doctors) {
        if (doctor->getId() == doctorId) {
            return doctor->getFullName();
        }
    }
    return "невідомо";
}

bool hasAcademicTitle(const std::string& degree) {
    return (degree.find("кандидат") != std::string::npos ||
        degree.find("доктор") != std::string::npos ||
        degree.find("доцент") != std::string::npos ||
        degree.find("професор") != std::string::npos);
}

bool isDateInRange(const std::tm& dateToCheck, const std::tm& startDate,
    const std::tm& endDate) {
    std::time_t timeToCheck = mktime(const_cast<std::tm*>(&dateToCheck));
    std::time_t startTime = mktime(const_cast<std::tm*>(&startDate));
    std::time_t endTime = mktime(const_cast<std::tm*>(&endDate));
    return (timeToCheck >= startTime && timeToCheck <= endTime);
}

int daysBetween(const std::tm& start, const std::tm& end) {
    std::time_t startTime = mktime(const_cast<std::tm*>(&start));
    std::time_t endTime = mktime(const_cast<std::tm*>(&end));
    if (startTime == -1 || endTime == -1) {
        return 1;
    }
    double diff = std::difftime(endTime, startTime) / (60 * 60 * 24);
    return static_cast<int>(diff) + 1;
}

std::tm getDateFromUser() {
    int year, month, day;
    char delimiter;
    std::cout << "Введіть дату у форматі РРРР-ММ-ДД: ";
    std::cin >> year >> delimiter >> month >> delimiter >> day;

    std::tm t{};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    std::mktime(&t);
    return t;
}

bool validateHeader(const std::string& line,
    const std::vector<std::string>& expected) {
    std::stringstream ss(line);
    std::vector<std::string> actual;
    std::string field;

    while (std::getline(ss, field, '\t')) {
        actual.push_back(field);
    }

    return actual == expected;
}