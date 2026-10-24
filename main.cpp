#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct MenuItem {
    int id;
    std::string category;
    std::string name;
    double price;
};

struct OrderItem {
    MenuItem item;
    int quantity;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= minValue && value <= maxValue) {
            clearInput();
            return value;
        }
        std::cout << "Invalid input. Enter a number from " << minValue
                  << " to " << maxValue << ".\n";
        clearInput();
    }
}

char readYesNo(const std::string& prompt) {
    char answer;
    while (true) {
        std::cout << prompt;
        if (std::cin >> answer) {
            clearInput();
            if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
                return answer;
        } else {
            clearInput();
        }
        std::cout << "Please enter Y or N.\n";
    }
}

void showMenu(const std::vector<MenuItem>& menu) {
    std::cout << "\n================ FOOD MENU ================\n";
    std::string currentCategory;
    for (const auto& item : menu) {
        if (item.category != currentCategory) {
            currentCategory = item.category;
            std::cout << "\n--- " << currentCategory << " ---\n";
        }
        std::cout << std::setw(2) << item.id << ") "
                  << std::left << std::setw(29) << item.name
                  << std::right << " Rs. " << std::fixed
                  << std::setprecision(2) << item.price << '\n';
    }
    std::cout << " 0) Checkout\n";
    std::cout << "===========================================\n";
}

int main() {
    const std::vector<MenuItem> menu = {
        {1, "Pizza", "Chicken Fajita Pizza", 250},
        {2, "Pizza", "Chicken Bar BQ Pizza", 500},
        {3, "Pizza", "Peri Peri Pizza", 900},
        {4, "Pizza", "Creamy Max Pizza", 450},
        {5, "Burgers", "Zinger Burger", 180},
        {6, "Burgers", "Chicken Burger", 150},
        {7, "Burgers", "Beef Burger", 160},
        {8, "Sandwiches", "Club Sandwich", 240},
        {9, "Sandwiches", "Chicken Crispy Sandwich", 160},
        {10, "Sandwiches", "Extreme Veg Sandwich", 100},
        {11, "Rolls", "Chicken Chutney Roll", 150},
        {12, "Rolls", "Chicken Mayo Roll", 100},
        {13, "Rolls", "Veg Roll with Fries", 120},
        {14, "Biryani", "Chicken Biryani", 160},
        {15, "Biryani", "Prawn Biryani", 220},
        {16, "Biryani", "Beef Biryani", 140}
    };

    std::string customerName;
    std::vector<OrderItem> cart;

    std::cout << "===========================================\n"
              << "       SIMPLE FOOD ORDERING SYSTEM\n"
              << "===========================================\n"
              << "Enter your name: ";
    std::getline(std::cin, customerName);
    if (customerName.empty()) customerName = "Customer";

    std::cout << "\nWelcome, " << customerName << "!\n";
    while (true) {
        showMenu(menu);
        int id = readInt("Choose an item number (0 to checkout): ", 0,
                         static_cast<int>(menu.size()));
        if (id == 0) break;

        int quantity = readInt("Enter quantity (1-99): ", 1, 99);
        const MenuItem& selected = menu.at(static_cast<std::size_t>(id - 1));

        bool found = false;
        for (auto& order : cart) {
            if (order.item.id == selected.id) {
                order.quantity += quantity;
                found = true;
                break;
            }
        }
        if (!found) cart.push_back({selected, quantity});

        std::cout << quantity << " x " << selected.name
                  << " added to your cart.\n";
        if (readYesNo("Would you like to order another item? (Y/N): ") == 'n')
            break;
    }

    std::cout << "\n================ YOUR RECEIPT ================\n";
    std::cout << "Customer: " << customerName << "\n";
    if (cart.empty()) {
        std::cout << "No items were ordered.\n";
    } else {
        double total = 0.0;
        std::cout << std::left << std::setw(29) << "Item"
                  << std::right << std::setw(7) << "Qty"
                  << std::setw(13) << "Price"
                  << std::setw(13) << "Amount" << '\n';
        std::cout << std::string(62, '-') << '\n';
        for (const auto& order : cart) {
            double amount = order.item.price * order.quantity;
            total += amount;
            std::cout << std::left << std::setw(29) << order.item.name
                      << std::right << std::setw(7) << order.quantity
                      << std::setw(13) << std::fixed << std::setprecision(2)
                      << order.item.price << std::setw(13) << amount << '\n';
        }
        std::cout << std::string(62, '-') << '\n'
                  << std::right << std::setw(49) << "Total: Rs. "
                  << std::fixed << std::setprecision(2) << total << '\n';
        std::cout << "Estimated delivery time: 40 minutes\n";
    }
    std::cout << "Thank you for ordering!\n";
    return 0;
}
