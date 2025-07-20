/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Event {
    string date;       // Format: YYYY-MM-DD
    string description;
};

class EventReminder {
private:
    vector<Event> events;

public:
    void addEvent() {
        Event e;
        cout << "Enter event date (YYYY-MM-DD): ";
        cin >> e.date;
        cin.ignore();
        cout << "Enter event description: ";
        getline(cin, e.description);
        events.push_back(e);
        cout << "✅ Event added successfully!\n";
    }

    void viewAllEvents() {
        if (events.empty()) {
            cout << "❌ No events to display.\n";
            return;
        }

        cout << "\n📅 All Events:\n";
        for (const auto& e : events) {
            cout << "Date: " << e.date << " | Description: " << e.description << "\n";
        }
    }

    void checkReminder() {
        string queryDate;
        cout << "Enter date to check (YYYY-MM-DD): ";
        cin >> queryDate;

        bool found = false;
        for (const auto& e : events) {
            if (e.date == queryDate) {
                cout << "🔔 Reminder for " << queryDate << ": " << e.description << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No reminders found for this date.\n";
        }
    }
};

int main() {
    EventReminder reminder;
    int choice;

    do {
        cout << "\n📆 Event Reminder Menu:\n";
        cout << "1. Add Event\n";
        cout << "2. View All Events\n";
        cout << "3. Check Reminder by Date\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: reminder.addEvent(); break;
            case 2: reminder.viewAllEvents(); break;
            case 3: reminder.checkReminder(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
