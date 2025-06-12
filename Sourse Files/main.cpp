#include "classes.h"
#include "data_loader.h"
#include "enums.h"
#include "helpers.h"
#include "queries.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <locale>
#include <memory>
#include <vector>

int main() {
    // Налаштування локалі
    try {
        std::locale::global(std::locale(""));
    }
    catch (...) {
        std::cerr << "Попередження: Не вдалося встановити локаль\n";
    }

    // Завантаження даних
    std::cout << "Завантаження даних...\n";
    auto medicalInstitutions = loadMedicalInstitutionsFromTXT();
    auto doctors = loadDoctorsFromTXT();
    auto patients = loadPatientsFromTXT();
    auto supportStaff = loadSupportStaffFromTXT();
    auto wards = loadWardsFromTXT();
    auto beds = loadBedsFromTXT();
    auto rooms = loadRoomsFromTXT();
    auto roomVisits = loadRoomVisitsFromTXT();
    auto operations = loadOperationsFromTXT();
    auto labTests = loadLabTestsFromTXT();

    // Перевірка завантажених даних
    if (medicalInstitutions.empty() || doctors.empty() || patients.empty() ||
        supportStaff.empty() || wards.empty() || beds.empty() || rooms.empty() ||
        roomVisits.empty() || operations.empty() || labTests.empty()) {
        std::cerr << "Помилка: Не вдалося завантажити всі необхідні дані\n";
        return 1;
    }

    std::cout << "Дані успішно завантажені:\n";
    std::cout << "- Медичні заклади: " << medicalInstitutions.size() << "\n";
    std::cout << "- Лікарі: " << doctors.size() << "\n";
    std::cout << "- Пацієнти: " << patients.size() << "\n";
    std::cout << "- Палати: " << wards.size() << "\n";
    std::cout << "- Ліжка: " << beds.size() << "\n";

    // Головний цикл меню
    int choice;
    do {
        std::cout << "\n=== Головне меню ===\n";
        std::cout << "1. Лікарі за профілем та закладом\n";
        std::cout << "2. Обслуговуючий персонал за посадою та закладом\n";
        std::cout << "3. Лікарі за профілем та мінімальною кількістю операцій\n";
        std::cout << "4. Лікарі за профілем та мінімальним стажем\n";
        std::cout << "5. Лікарі за профілем та науковим ступенем/званням\n";
        std::cout << "6. Пацієнти за місцем перебування\n";
        std::cout << "7. Пацієнти за періодом лікування\n";
        std::cout << "8. Пацієнти у лікаря за профілем в поліклініці\n";
        std::cout << "9. Ліжка за статусом та закладом\n";
        std::cout << "10. Аналіз кабінетів поліклініки та кількість відвідувань\n";
        std::cout
            << "11. Продуктивність лікарів (середня кількість прийомів за день)\n";
        std::cout << "12. Завантаження лікарів (кількість пацієнтів)\n";
        std::cout << "13. Перелік пацієнтів, які перенесли операції у зазначеній "
            "період\n";
        std::cout << "14. Аналіз продуктивності лабораторії (середня кількість "
            "тестів за день)\n";
        std::cout << "0. Вихід\n";
        std::cout << "Оберіть опцію: ";
        std::cin >> choice;

        // Обробка вибору користувача
        switch (choice) {
        case 1: {
            std::string specialty;
            int institutionId;
            std::cout << "Введіть спеціальність лікаря: ";
            std::cin.ignore();
            std::getline(std::cin, specialty);
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            query1_getDoctorsBySpecialtyAndInstitution(doctors, medicalInstitutions,
                specialty, institutionId);
            break;
        }
        case 2: {
            std::string role;
            int institutionId;
            std::cout << "Введіть посаду персоналу: ";
            std::cin.ignore();
            std::getline(std::cin, role);
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            query2_getSupportStaffByRoleAndInstitution(
                supportStaff, medicalInstitutions, role, institutionId);
            break;
        }
        case 3: {
            std::string specialty;
            int minOperations, institutionId;
            std::cout << "Введіть спеціальність лікаря: ";
            std::cin.ignore();
            std::getline(std::cin, specialty);
            std::cout << "Введіть мінімальну кількість операцій: ";
            std::cin >> minOperations;
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            query3_getDoctorsBySpecialtyAndMinOperations(doctors, medicalInstitutions,
                specialty, minOperations,
                institutionId);
            break;
        }
        case 4: {
            std::string specialty;
            int minExperience, institutionId;
            std::cout << "Введіть спеціальність лікаря: ";
            std::cin.ignore();
            std::getline(std::cin, specialty);
            std::cout << "Введіть мінімальний стаж роботи (років): ";
            std::cin >> minExperience;
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            query4_getDoctorsBySpecialtyAndMinExperience(doctors, medicalInstitutions,
                specialty, minExperience,
                institutionId);
            break;
        }
        case 5: {
            std::string specialty;
            int institutionId;
            std::cout << "Введіть спеціальність лікаря: ";
            std::cin.ignore();
            std::getline(std::cin, specialty);
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            query5_getDoctorsBySpecialtyAndAcademicTitle(doctors, medicalInstitutions,
                specialty, institutionId);
            break;
        }
        case 6: {
            int institutionId, wardId;
            std::string department;
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            std::cout
                << "Введіть назву відділення (залиште порожнім, якщо не потрібно): ";
            std::cin.ignore();
            std::getline(std::cin, department);
            std::cout << "Введіть ID палати (0, якщо не потрібно): ";
            std::cin >> wardId;
            query6_getPatientsByLocation(patients, medicalInstitutions, doctors,
                wards, institutionId, department, wardId);
            break;
        }
        case 7: {
            int institutionId, wardId, doctorId;
            std::tm startDate{}, endDate{};
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            std::cout << "Введіть ID палати (0, якщо не потрібно): ";
            std::cin >> wardId;
            std::cout << "Введіть ID лікаря (0, якщо не потрібно): ";
            std::cin >> doctorId;
            char filter;
            std::cout << "Фільтрувати за періодом? (y/n): ";
            std::cin >> filter;
            if (filter == 'y' || filter == 'Y') {
                std::cout << "Введіть початкову дату (РРРР-ММ-ДД): ";
                startDate = getDateFromUser();
                std::cout << "Введіть кінцеву дату (РРРР-ММ-ДД): ";
                endDate = getDateFromUser();
            }
            query7_getPatientsByTreatmentPeriod(patients, medicalInstitutions,
                doctors, wards, institutionId, wardId,
                doctorId, startDate, endDate);
            break;
        }
        case 8: {
            std::string specialty;
            int polyclinicId;
            std::cout << "Введіть спеціальність лікаря: ";
            std::cin.ignore();
            std::getline(std::cin, specialty);
            std::cout << "Введіть ID поліклініки: ";
            std::cin >> polyclinicId;
            query8_getPatientsByDoctorSpecialtyAndPolyclinic(
                patients, medicalInstitutions, doctors, specialty, polyclinicId);
            break;
        }
        case 9: {
            int institutionId;
            BedStatus status;
            int statusChoice;
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            std::cout << "Оберіть статус ліжка (1 - вільне, 2 - зайняте): ";
            std::cin >> statusChoice;
            status = (statusChoice == 1) ? BedStatus::free : BedStatus::occupied;
            query9_getTotalBedsByInstitutionAndStatus(
                wards, beds, medicalInstitutions, institutionId, status);
            break;
        }
        case 10: {
            int polyclinicId;
            std::tm startDate{}, endDate{};
            std::cout << "Введіть ID поліклініки: ";
            std::cin >> polyclinicId;
            std::cout << "Введіть початкову дату періоду (РРРР-ММ-ДД): ";
            startDate = getDateFromUser();
            std::cout << "Введіть кінцеву дату періоду (РРРР-ММ-ДД): ";
            endDate = getDateFromUser();
            query10_getRoomsAndVisitsByPolyclinic(rooms, roomVisits,
                medicalInstitutions, polyclinicId,
                startDate, endDate);
            break;
        }
        case 11: {
            int doctorId = 0, polyclinicId = 0;
            std::string specialty;
            std::tm startDate{}, endDate{};
            std::cout << "Оберіть варіант (1 - конкретний лікар, 2 - всі лікарі "
                "поліклініки, 3 - всі лікарі профілю): ";
            int option;
            std::cin >> option;
            if (option == 1) {
                std::cout << "Введіть ID лікаря: ";
                std::cin >> doctorId;
            }
            else if (option == 2) {
                std::cout << "Введіть ID поліклініки: ";
                std::cin >> polyclinicId;
            }
            else if (option == 3) {
                std::cout << "Введіть спеціальність лікарів: ";
                std::cin.ignore();
                std::getline(std::cin, specialty);
            }
            std::cout << "Введіть початкову дату періоду (РРРР-ММ-ДД): ";
            startDate = getDateFromUser();
            std::cout << "Введіть кінцеву дату періоду (РРРР-ММ-ДД): ";
            endDate = getDateFromUser();
            query11_getDoctorProductivity(doctors, roomVisits, medicalInstitutions,
                doctorId, polyclinicId, specialty,
                startDate, endDate);
            break;
        }
        case 12: {
            int doctorId = 0, hospitalId = 0;
            std::string specialty;
            std::cout << "Оберіть варіант (1 - конкретний лікар, 2 - всі лікарі "
                "лікарні, 3 - всі лікарі профілю): ";
            int option;
            std::cin >> option;
            if (option == 1) {
                std::cout << "Введіть ID лікаря: ";
                std::cin >> doctorId;
            }
            else if (option == 2) {
                std::cout << "Введіть ID лікарні: ";
                std::cin >> hospitalId;
            }
            else if (option == 3) {
                std::cout << "Введіть спеціальність лікарів: ";
                std::cin.ignore();
                std::getline(std::cin, specialty);
            }
            query12_getDoctorWorkload(doctors, patients, medicalInstitutions,
                doctorId, hospitalId, specialty);
            break;
        }
        case 13: {
            int hospitalId = 0, polyclinicId = 0, doctorId = 0;
            std::tm startDate{}, endDate{};
            std::cout << "Оберіть варіант (1 - конкретний лікар, 2 - лікарня, 3 - "
                "поліклініка): ";
            int option;
            std::cin >> option;
            if (option == 1) {
                std::cout << "Введіть ID лікаря: ";
                std::cin >> doctorId;
            }
            else if (option == 2) {
                std::cout << "Введіть ID лікарні: ";
                std::cin >> hospitalId;
            }
            else if (option == 3) {
                std::cout << "Введіть ID поліклініки: ";
                std::cin >> polyclinicId;
            }
            std::cout << "Введіть початкову дату періоду (РРРР-ММ-ДД): ";
            startDate = getDateFromUser();
            std::cout << "Введіть кінцеву дату періоду (РРРР-ММ-ДД): ";
            endDate = getDateFromUser();
            query13_getPatientsWithOperations(
                patients, operations, doctors, medicalInstitutions, hospitalId,
                polyclinicId, doctorId, startDate, endDate);
            break;
        }
        case 14: {
            int institutionId;
            std::tm startDate{}, endDate{};
            std::cout << "Введіть ID медичного закладу (0 для всіх): ";
            std::cin >> institutionId;
            std::cout << "Введіть початкову дату періоду (РРРР-ММ-ДД): ";
            startDate = getDateFromUser();
            std::cout << "Введіть кінцеву дату періоду (РРРР-ММ-ДД): ";
            endDate = getDateFromUser();
            query14_getLabProductivity(labTests, medicalInstitutions, institutionId,
                startDate, endDate);
            break;
        }
        case 0:
            std::cout << "Завершення роботи програми...\n";
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }

        if (choice != 0) {
            std::cout << "\nНатисніть Enter для продовження...";
            std::cin.ignore();
            std::cin.get();
        }
    } while (choice != 0);

    return 0;
}