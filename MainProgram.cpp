// ================================
// CLASS: Temperature
// ================================
class Temperature {
private:
    double celsius_;

public:
    explicit Temperature(double celsius) {
        if (celsius < -273.15)
            throw invalid_argument("Temperature below absolute zero!");
        celsius_ = celsius;
    }

    double getCelsius() const {
        return celsius_;
    }

    double getFahrenheit() const {
        return celsius_ * 9.0 / 5.0 + 32;
    }

    void setCelsius(double celsius) {
        if (celsius < -273.15)
            throw invalid_argument("Temperature below absolute zero!");
        celsius_ = celsius;
    }
};

// ================================
// CLASS: BankAccount
// ================================
class BankAccount {
private:
    string owner_;
    double balance_;

public:
    BankAccount(const string& owner, double initialBalance) {
        if (owner.empty())
            throw invalid_argument("Owner cannot be empty!");
        if (initialBalance < 0)
            throw invalid_argument("Balance cannot be negative!");

        owner_ = owner;
        balance_ = initialBalance;
    }

    string getOwner() const {
        return owner_;
    }

    double getBalance() const {
        return balance_;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Deposit must be positive!");

        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Withdraw must be positive!");

        if (amount > balance_)
            throw runtime_error("Insufficient funds!");

        balance_ -= amount;
    }

    void transfer(BankAccount& other, double amount) {
        withdraw(amount);
        other.deposit(amount);
    }
};

// ================================
// CLASS: Password
// ================================
class Password {
private:
    string password_;

    static bool hasDigit(const string& s) {
        for (char c : s) {
            if (isdigit(c))
                return true;
        }
        return false;
    }

    static void validate(const string& pwd) {
        if (pwd.length() < 8)
            throw invalid_argument("Password must be at least 8 characters!");

        if (!hasDigit(pwd))
            throw invalid_argument("Password must contain at least one digit!");
    }

public:
    explicit Password(const string& pwd) {
        validate(pwd);
        password_ = pwd;
    }

    void change(const string& oldPassword, const string& newPassword) {
        if (oldPassword != password_)
            throw invalid_argument("Old password incorrect!");

        validate(newPassword);
        password_ = newPassword;
    }

    bool matches(const string& attempt) const {
        return attempt == password_;
    }

    size_t getLength() const {
        return password_.length();
    }
};
