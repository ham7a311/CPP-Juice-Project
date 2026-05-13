# 🍹 Juice Shop System (OOP)

## 💡 Core Idea

A juice shop system that allows:
- Displaying a menu of juices  
- Creating customer orders  
- Choosing size (Small / Medium / Large)  
- Calculating prices  
- Creating custom juices (Juice Builder)  
- Managing orders and employees  

---

## 🧱 System Design (Classes)

### 👤 1. Customer

Represents the person placing an order.

**Properties:**
- `customerID`
- `name`
- `phone` (optional)

**Functions:**
- `placeOrder()`

---

### 🧑‍🍳 2. Employee

Manages the system and orders.

**Properties:**
- `employeeID`
- `name`
- `role`

**Functions:**
- `processOrder()`
- `addJuiceToMenu()`

---

### 🧃 3. Juice (Base Class)

The most important class in the system.

**Properties:**
- `juiceName`
- `basePrice`

**Functions:**
- `calculatePrice(size)`
- `displayJuiceInfo()`

---

### 🍹 4. Menu

Stores available juices.

**Properties:**
- `list<Juice> availableJuices`

**Functions:**
- `showMenu()`
- `addJuice()`
- `removeJuice()`
- `searchJuice()`

---

### 🧾 5. Order

Represents a customer order.

**Properties:**
- `orderID`
- `customer`
- `list<Juice>`
- `totalPrice`
- `status (Pending / Completed)`

**Functions:**
- `addJuiceToOrder()`
- `calculateTotal()`
- `showOrderDetails()`

---

### 🏪 6. JuiceShop (Main System)

The main controller of the system.

**Properties:**
- `menu`
- `orders`
- `employees`

**Functions:**
- `createOrder()`
- `displayAllOrders()`
- `manageMenu()`
- `checkoutOrder()`

---

### 🍓 7. JuiceBuilder

Allows the customer to create a custom juice.

**Properties:**
- `baseJuice` (optional)
- `ingredients`
- `extraPrice`

**Functions:**
- `addIngredient()`
- `removeIngredient()`
- `calculateCustomPrice()`
- `createCustomJuice()`

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

3️⃣ **Juice Builder (Optional)**
- Select ingredients  
- Automatically calculate price  
- Create a custom juice  
- Add it to the order  

4️⃣ **Checkout**
- Display final bill  
- Update order status to Completed  
