#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class from Snippet 1
class mobile {
private:
    char brand[50];
    int modelno;
    float price;
public:
    void input() {
        cout << "enter the price" << endl;
        cin >> price;
        cout << "enter the brand name" << endl;
        cin >> brand;
        cout << "enter the model no" << endl;
        cin >> modelno;
    }
    void output() {
        cout << " price:" << price << endl;
        cout << "brand:" << brand << endl;
        cout << "modelNo:" << modelno << endl;
    }
};

// Function from Snippet 2
void addMobile(string name, string processor = "A18") {
    cout << "Mobile Name:" << name << endl;
    cout << "processor:" << processor << endl;
    cout << "---------------" << endl;
}

// Class from Snippet 3
class MobileReport {
private:
    string mobileID;
    string brand;
    string model;
    int storage;
    double price;
public:
    void registerMobile() {
        cin.ignore(); // Add this to handle the newline character from previous inputs
        cout << "Enter Mobile ID     : ";
        getline(cin, mobileID);
        cout << "Enter Brand         : ";
        getline(cin, brand);
        cout << "Enter Model         : ";
        getline(cin, model);
        cout << "Enter Storage  : ";
        cin >> storage;
        cin.ignore();
        cout << "Enter Price         : ";
        cin >> price;
        cin.ignore();
    }
    friend void showMobileReport(const MobileReport& m);
};
void showMobileReport(const MobileReport& m) {
    string segment;
    if (m.price >= 60000)
        segment = "Premium";
    else if (m.price >= 30000)
        segment = "Mid-Range";
    else
        segment = "Budget";
    cout << "\n========== MOBILE REPORT ==========" << endl;
    cout << "Mobile ID    : " << m.mobileID << endl;
    cout << "Brand        : " << m.brand << endl;
    cout << "Model        : " << m.model << endl;
    cout << "Storage      : " << m.storage << endl;
    cout << "Price        : " << m.price << endl;
    cout << "Segment      : " << segment << endl;
    cout << "===================================\n";
}

// Class from Snippet 4
class MobileRegistration {
private:
    string brand;
    int storage;
    string model;
    string mobileID;
public:
    MobileRegistration() {
        brand = "Not Given";
        storage = 0;
        model = "General Model";
        mobileID = "Unknown";
    }
    MobileRegistration(string id, string brand, int storage, string model) {
        this->mobileID = id;
        this->brand = brand;
        this->storage = storage;
        this->model = model;
    }
    void display() {
        cout << "\n======= MOBILE DETAILS =======\n";
        cout << "Mobile ID    : " << mobileID << endl;
        cout << "Brand        : " << brand << endl;
        cout << "Storage(GB)  : " << storage << endl;
        cout << "Model        : " << model << endl;
        cout << "================================\n";
    }
};

// Class from Snippet 5
class MobileAnalysis {
private:
    string brand;
    int storage;
    string model;
    string condition;
    string mobileID;
public:
    MobileAnalysis() {
        brand = "Not Given";
        storage = 0;
        model = "General Model";
        condition = "new";
        mobileID = "0000";
    }
    bool isDigitsOnly(const string& str) {
        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] < '0' || str[i] > '9')
                return false;
        }
        return true;
    }
    int stringToInt(const string& s) {
        int result = 0;
        for (size_t i = 0; i < s.length(); ++i)
            result = result * 10 + (s[i] - '0');
        return result;
    }
    void getData() {
        while (true) {
            cout << "Enter Mobile ID      : ";
            getline(cin, mobileID);
            if (!mobileID.empty() && isDigitsOnly(mobileID)) break;
            cout << "? Mobile ID must contain digits only and no blank spaces. Try again.\n";
        }
        while (true) {
            cout << "Enter Brand          : ";
            getline(cin, brand);
            bool valid = true;
            for (size_t j = 0; j < brand.length(); j++) {
                if (brand[j] >= '0' && brand[j] <= '9') {
                    cout << "? Brand cannot contain numbers and no blank spaces. Try again.\n";
                    valid = false;
                    break;
                }
            }
            if (valid && !brand.empty()) break;
        }
        while (true) {
            string storageInput;
            cout << "Enter Storage (GB)   : ";
            getline(cin, storageInput);
            if (storageInput.empty()) {
                storage = 0;
                break;
            }
            bool valid = isDigitsOnly(storageInput);
            if (valid) {
                storage = stringToInt(storageInput);
                break;
            }
            cout << "? Storage must be a number and no blank spaces. Try again.\n";
        }
        cout << "Enter Model          : ";
        getline(cin, model);
        while (true) {
            cout << "Enter Condition (new/used/refurbished): ";
            getline(cin, condition);
            if (condition == "new" || condition == "used" || condition == "refurbished") break;
            cout << "? Please enter a valid condition.\n";
        }
    }
    void display(string tag = "") {
        cout << "\n--- Mobile Details (" << tag << ") ---\n";
        cout << "Mobile ID      : " << mobileID << endl;
        cout << "Brand          : " << brand << endl;
        cout << "Storage (GB)   : " << storage << endl;
        cout << "Model          : " << model << endl;
        cout << "Condition      : " << condition << endl;
        suggestCategory();
    }
    void suggestCategory() {
        cout << "Category       : ";
        if (model == "iPhone" || model == "Galaxy" || model == "Pixel")
            cout << "Premium";
        else if (model == "Redmi" || model == "Realme" || model == "Poco")
            cout << "Budget";
        else if (model == "OnePlus" || model == "Nothing")
            cout << "Mid-Range";
        else
            cout << "General";
        cout << endl;
    }
    void analyze(int storage, string condition) {
        cout << "\n--- Usage Analysis ---\n";
        if (condition == "used" && storage < 64)
            cout << "Usage Level    : High\n";
        else if (condition == "refurbished" || storage < 128)
            cout << "Usage Level    : Moderate\n";
        else
            cout << "Usage Level    : Low\n";
    }
    string getCondition() { return condition; }
    int getStorage() { return storage; }
};

// Class from Snippet 6
class Shop {
private:
    string name;
    int inventory;
    int dailySales;
    string status;
    string category;
    void updateCategory() {
        if (status == "out of business") category = "Closed";
        else if (inventory > 500) category = "Thriving";
        else if (inventory > 200) category = "Stable";
        else category = "Struggling";
    }
public:
    Shop(string n = "Generic Shop", int inv = 0, int sales = 0, string stat = "open")
        : name(n), inventory(inv), dailySales(sales), status(stat) {
        updateCategory();
    }
    void display(string tag = "") const {
        cout << "\n--- Shop Details (" << tag << ") ---\n";
        cout << "Name        : " << name << endl;
        cout << "Inventory   : " << inventory << endl;
        cout << "Daily Sales : " << dailySales << endl;
        cout << "Status      : " << status << endl;
        cout << "Category    : " << category << endl;
    }
    Shop& operator++() {
        if (status == "open") inventory += 100;
        else if (status == "closed") inventory += 50;
        else if (status == "renovating") inventory += 30;
        updateCategory();
        return *this;
    }
    Shop& operator--() {
        if (status == "open") inventory -= dailySales;
        else if (status == "closed") inventory -= dailySales / 4;
        else if (status == "renovating") inventory -= dailySales / 2;
        if (inventory < 0) inventory = 0;
        updateCategory();
        return *this;
    }
    Shop& operator!() {
        if (status == "open") status = "closed";
        else if (status == "closed") status = "renovating";
        else if (status == "renovating") status = "open";
        updateCategory();
        return *this;
    }
    Shop& operator-() {
        status = "out of business";
        inventory = 0;
        dailySales = 0;
        updateCategory();
        return *this;
    }
};

// Class from Snippet 7
class MobileStock {
private:
    string brand;
    string model;
    double price;
    int quantity;
public:
    MobileStock(string b = "", string m = "", double p = 0.0, int q = 0) {
        brand = b;
        model = m;
        price = p;
        quantity = q;
    }
    void input() {
        cout << "Enter Brand: ";
        getline(cin, brand);
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Price: $";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cin.ignore();
    }
    void display() {
        cout << "Brand: " << brand
             << ", Model: " << model
             << ", Price: $" << price
             << ", Quantity: " << quantity << endl;
    }
    MobileStock operator+(MobileStock &m) {
        if (brand == m.brand && model == m.model && price == m.price) {
            return MobileStock(brand, model, price, quantity + m.quantity);
        } else {
            cout << "?? Mobiles are different! Cannot add stock." << endl;
            return *this;
        }
    }
};

// Class from Snippet 8
class MobileStore {
private:
    string model;
    double price;
    static string storeName;
    static int totalMobilesSold;
public:
    MobileStore(string m, double p) {
        model = m;
        price = p;
    }
    static void updateSales(int count) {
        totalMobilesSold += count;
        cout << "\n Sales updated. Total mobiles sold: " << totalMobilesSold << endl;
    }
    static void displayStoreInfo() {
        cout << "\n Welcome to " << storeName << endl;
        cout << "Total mobiles sold so far: " << totalMobilesSold << endl;
    }
    void displayMobile() {
        cout << "Model: " << model << " | Price: " << price << endl;
    }
};
string MobileStore::storeName = "TechWorld Mobiles";
int MobileStore::totalMobilesSold = 0;

// Class from Snippet 9
class Mobile_Inheritance {
protected:
    string brand;
    string model;
public:
    void setMobile() {
        cin.ignore();
        cout << "Enter Mobile Brand: ";
        getline(cin, brand);
        cout << "Enter Mobile Model: ";
        getline(cin, model);
    }
    void displayMobile() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }
};
class Smartphone_Inheritance : public Mobile_Inheritance {
protected:
    int ram;
    int storage;
public:
    void setSmartphone() {
        cout << "Enter RAM (in GB): ";
        cin >> ram;
        cout << "Enter Storage (in GB): ";
        cin >> storage;
        cin.ignore();
    }
    void displaySmartphone() {
        displayMobile();
        cout << "RAM: " << ram << "GB, Storage: " << storage << "GB" << endl;
    }
};
class Stock_Inheritance : public Smartphone_Inheritance {
private:
    int quantity;
    double price;
public:
    void setStock() {
        cout << "Enter Quantity in Stock: ";
        cin >> quantity;
        cout << "Enter Price: $";
        cin >> price;
    }
    void displayStock() {
        displaySmartphone();
        cout << "Quantity in stock: " << quantity
             << ", Price: $" << price << endl;
    }
};

// Class from Snippet 10
class Supplier {
protected:
    string supplierName;
    string contact;
public:
    void setSupplier() {
        cin.ignore();
        cout << "Enter Supplier Name: ";
        getline(cin, supplierName);
        cout << "Enter Supplier Contact: ";
        getline(cin, contact);
    }
    void displaySupplier() {
        cout << "Supplier: " << supplierName
             << ", Contact: " << contact << endl;
    }
};
class Warranty {
protected:
    int warrantyYears;
public:
    void setWarranty() {
        cout << "Enter Warranty Period (in years): ";
        cin >> warrantyYears;
        cin.ignore();
    }
    void displayWarranty() {
        cout << "Warranty: " << warrantyYears << " years" << endl;
    }
};
class Mobile_Multi : public Supplier, public Warranty {
private:
    string brand;
    string model;
    double price;
public:
    void setMobile() {
        cout << "Enter Mobile Brand: ";
        getline(cin, brand);
        cout << "Enter Mobile Model: ";
        getline(cin, model);
        cout << "Enter Price: $";
        cin >> price;
        cin.ignore();
    }
    void displayMobile() {
        cout << "Brand: " << brand << ", Model: " << model
             << ", Price: $" << price << endl;
        displaySupplier();
        displayWarranty();
    }
};

// Function wrappers for each main() logic
void runExample1() {
    mobile m;
    m.input();
    m.output();
}
void runExample2() {
    addMobile("IPhone 15 Pro", "A18 Pro");
    addMobile("IPhone 15");
}
void runExample3() {
    MobileReport phone;
    cout << "===== Enter Mobile Details =====\n";
    phone.registerMobile();
    showMobileReport(phone);
}
void runExample4() {
    int num;
    cout << "\nHow many mobiles do you want to register? ";
    cin >> num;
    cin.ignore();
    for (int i = 1; i <= num; i++) {
        cout << "\n--- Enter details for Mobile #" << i << " ---\n";
        string id, brand, model, choice;
        int storage;
        cout << "Enter Mobile ID     : ";
        getline(cin, id);
        cout << "Enter Brand Name    : ";
        getline(cin, brand);
        bool has_digit = false;
        // Corrected for-loop
        for (size_t j = 0; j < brand.length(); ++j) {
            if (brand[j] >= '0' && brand[j] <= '9') {
                cout << "? Brand cannot contain numbers. Please re-enter mobile.\n";
                i--;
                has_digit = true;
                break;
            }
        }
        if (has_digit) continue;
        cout << "Enter Storage (GB)  : ";
        cin >> storage;
        cin.ignore();
        cout << "Do you want to enter model? (yes/no): ";
        getline(cin, choice);
        MobileRegistration m;
        if (choice == "no" || choice == "No") {
            m = MobileRegistration();
        } else {
            cout << "Enter Model         : ";
            getline(cin, model);
            m = MobileRegistration(id, brand, storage, model);
        }
        m.display();
    }
    cout << "\n All mobiles registered successfully.\n";
}
void runExample5() {
    int numMobiles = 1;
    string input;
    cout << "How many mobiles do you want to register? ";
    getline(cin, input);
    if (!input.empty()) {
        MobileAnalysis temp;
        if (temp.isDigitsOnly(input)) {
            numMobiles = temp.stringToInt(input);
        }
    }
    for (int i = 0; i < numMobiles; i++) {
        cout << "\n--- Registering Mobile " << i + 1 << " ---\n";
        MobileAnalysis m;
        m.getData();
        m.display("Initial");
        m.analyze(m.getStorage(), m.getCondition());
    }
}
void runExample6() {
    string shopName, status;
    int inventory, sales;
    cout << "Enter shop name: ";
    getline(cin, shopName);
    cout << "Enter initial inventory: ";
    cin >> inventory;
    cout << "Enter daily sales: ";
    cin >> sales;
    cin.ignore();
    cout << "Enter shop status (open/closed/renovating): ";
    getline(cin, status);
    Shop s1(shopName, inventory, sales, status);
    s1.display("Original");
    cout << "\nApplying ++ (Restock)...";
    ++s1;
    s1.display("After ++");
    cout << "\nApplying -- (Sales)...";
    --s1;
    s1.display("After --");
    cout << "\nApplying ! (Status cycle)...";
    !s1;
    s1.display("After !");
    cout << "\nApplying - (Close permanently)...";
    -s1;
    s1.display("After -");
}
void runExample7() {
    cin.ignore();
    cout << "--- Enter details of Mobile 1 ---" << endl;
    MobileStock m1;
    m1.input();
    cout << "\n--- Enter details of Mobile 2 ---" << endl;
    MobileStock m2;
    m2.input();
    cout << "\n--- Mobile 1 ---" << endl;
    m1.display();
    cout << "--- Mobile 2 ---" << endl;
    m2.display();
    cout << "\n--- Result of Adding Stock (m1 + m2) ---" << endl;
    MobileStock m3 = m1 + m2;
    m3.display();
}
void runExample8() {
    vector<MobileStore> inventory;
    int choice;
    do {
        cout << "\n===== Mobile Store Menu =====";
        cout << "\n1. Add Mobile";
        cout << "\n2. View Inventory";
        cout << "\n3. Sell Mobiles";
        cout << "\n4. View Store Info";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string model;
            double price;
            cout << "Enter mobile model: ";
            cin >> ws;
            getline(cin, model);
            cout << "Enter price: ";
            cin >> price;
            inventory.push_back(MobileStore(model, price));
            cout << " Mobile added to inventory!" << endl;
        } else if (choice == 2) {
            cout << "\n Current Inventory:\n";
            if (inventory.empty()) {
                cout << "No mobiles available in stock.\n";
            } else {
                for (size_t i = 0; i < inventory.size(); i++) {
                    cout << (i + 1) << ". ";
                    inventory[i].displayMobile();
                }
            }
        } else if (choice == 3) {
            int count;
            cout << "Enter number of mobiles sold: ";
            cin >> count;
            MobileStore::updateSales(count);
        } else if (choice == 4) {
            MobileStore::displayStoreInfo();
        } else if (choice == 0) {
            cout << "Exiting Mobile Store system. Goodbye!\n";
        } else {
            cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
void runExample9() {
    Stock_Inheritance s;
    cout << "--- Enter Mobile Store Details ---" << endl;
    s.setMobile();
    s.setSmartphone();
    s.setStock();
    cout << "\n--- Mobile Store Stock Details ---" << endl;
    s.displayStock();
}
void runExample10() {
    Mobile_Multi m;
    cout << "--- Enter Mobile Store Details ---" << endl;
    m.setSupplier();
    m.setWarranty();
    m.setMobile();
    cout << "\n--- Mobile Details ---" << endl;
    m.displayMobile();
}

// Single main function to act as a menu
int main() {
    int choice;
    cout << "Choose which example to run (1-10):\n";
    cout << "1. Basic Class & Objects\n";
    cout << "2. Default Function Arguments\n";
    cout << "3. Friend Function\n";
    cout << "4. Loops and Object Creation\n";
    cout << "5. Input Validation & Analysis\n";
    cout << "6. Operator Overloading\n";
    cout << "7. Operator Overloading for Stock\n";
    cout << "8. Static Members & Vector\n";
    cout << "9. Multilevel Inheritance\n";
    cout << "10. Multiple Inheritance\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1: runExample1(); break;
        case 2: runExample2(); break;
        case 3: runExample3(); break;
        case 4: runExample4(); break;
        case 5: runExample5(); break;
        case 6: runExample6(); break;
        case 7: runExample7(); break;
        case 8: runExample8(); break;
        case 9: runExample9(); break;
        case 10: runExample10(); break;
        default: cout << "Invalid choice.\n"; break;
    }
    return 0;
}
