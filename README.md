# 🍹 Juice Shop System (OOP)

## 💡 Core Idea

A juice shop system that allows:
- Displaying a menu of juices  
- Creating customer orders  
- Choosing size (Small / Medium / Large)  
- Calculating prices  
- Creating custom juices (Juice Builder)  
- Managing orders and employees  
- Checkout using multiple payment methods  

---

# OOP Concepts Used

- Encapsulation
- Inheritance
- Polymorphism
- Abstraction
- Operator Overloading
- Exception Handling
- Builder Design Pattern

---

## 🧱 System Design (Classes)

### 👤 1. Person (Base Class)

Base class for Customer and Employee.

**Properties:**
- `name`
- `phoneNumber`

**Functions:**
- `displayPersonInfo()`

---

### 👤 2. Customer

Represents the person placing an order.

**Inheritance:**
- Inherits from `Person`

**Properties:**
- `customerID`

**Functions:**
- `placeOrder()`
- `displayPersonInfo()` (override)

---

### 🧑‍🍳 3. Employee

Manages the system and orders.

**Inheritance:**
- Inherits from `Person`

**Properties:**
- `employeeID`
- `role`

**Functions:**
- `processOrder()`
- `addJuiceToMenu()`
- `displayPersonInfo()` (override)

---

### 🧃 4. Juice

The most important class in the system.

**Properties:**
- `juiceName`
- `basePrice`

**Functions:**
- `calculatePrice(size)`
- `displayJuiceInfo()`

**Operator Overloading:**
- `operator==()` to compare juice names

---

### 🍹 5. Menu

Stores available juices.

**Properties:**
- `vector<Juice> availableJuices`

**Functions:**
- `showMenu()`
- `addJuice()`
- `removeJuice()`
- `getJuice()`

---

### 🧾 6. Order

Represents a customer order.

**Properties:**
- `orderID`
- `customer`
- `vector<pair<Juice, char>> juices`
- `totalPrice`
- `status (Pending / Completed)`

**Functions:**
- `addJuiceToOrder()`
- `calculateTotal()`
- `showOrderDetails()`
- `completeOrder()`

**Operator Overloading:**
- `operator<<` to display order details

---

### 💳 7. Payment (Abstract Class)

Base class for payment methods.

**Properties:**
- `amount`
- `paymentMethod`

**Functions:**
- `processPayment()` (pure virtual)
- `displayPaymentInfo()`
- `showPaymentMethods()`

---

### 💵 8. CashPayment

Handles cash payments.

**Inheritance:**
- Inherits from `Payment`

**Properties:**
- `cashGiven`

**Functions:**
- `processPayment()`
- `calculateChange()`

---

### 💳 9. VisaPayment

Handles Visa card payments.

**Inheritance:**
- Inherits from `Payment`

**Properties:**
- `cardNumber`

**Functions:**
- `processPayment()`

---

### 💳 10. AmericanExpressPayment

Handles American Express card payments.

**Inheritance:**
- Inherits from `Payment`

**Properties:**
- `cardNumber`

**Functions:**
- `processPayment()`

---

### 🏪 11. JuiceShop (Main System)

The main controller of the system.

**Properties:**
- `menu`
- `orders`
- `employees`

**Functions:**
- `createOrder()`
- `displayOrders()`
- `checkOrder()`
- `checkoutOrder()`

---

### 🍓 12. JuiceBuilder

Allows the customer to create a custom juice.

**Properties:**
- `availableIngredients`
- `selectedIngredients`
- `basePrice`
- `ingredientPrice`

**Functions:**
- `showAvailableIngredients()`
- `addIngredient()`
- `removeIngredient()`
- `calculateCustomPrice()`
- `createCustomJuice()`
- `displayCustomMix()`

**Available Ingredients:**
- Mango
- Strawberry
- Banana
- Pineapple
- Mint
- Ice

Each ingredient adds a small extra cost to the final price.

---

## 🧭 Main System Scenario

1️⃣ **Show Menu**  
Display all available juices with their prices.

2️⃣ **Create Order**
- Enter customer name  
- Choose juice  
- Select size  
- Calculate price  
- Save order  

3️⃣ **Juice Builder**
- Select ingredients  
- Automatically calculate price  
- Create a custom juice  

4️⃣ **View Orders**
- Display all current orders

5️⃣ **Checkout**
- Enter order ID
- Choose payment method
- Complete payment
- Update order status to Completed

---

# ⚠️ Exception Handling

The system handles invalid cases using:
- `throw`
- `try`
- `catch`

For example:
- Invalid payment method
- Invalid juice name
- Invalid juice size
- Negative cash amount
- Insufficient cash payment
- Creating custom juice without ingredients

---

# ▶️ Try It Yourself

## 1. Clone the repository
```bash
git clone https://github.com/ham7a311/CPP-Juice-Project.git
```
## 2. cd to Project folder
```bash
cd CPP-Juice-Project
```
## 3. cd to Folder that includes the code
```bash
cd "Main Program"
```
## 4. Compile using C++20 features
```bash
clang++ -std=c++20 *.cpp -o main
```
## 5. Run the file
```bash
./main
```
