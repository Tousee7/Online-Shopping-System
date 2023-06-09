# Online Shopping System

This is an online shopping system project developed using object-oriented programming concepts in C++. It provides a platform for sellers to sell products, update and delete their products, and for buyers to purchase products. Users can create an account, log in, and update their account information.

## Features

- Account Creation: Sellers and buyers can create their accounts by providing necessary details such as username, password, and contact information.

- Login System: Users can log in using their registered credentials to access their respective accounts.

- Seller Functions:
  - Add Product: Sellers can add products to their inventory by providing details like product name, price, quantity, etc.
  - Update Product: Sellers can update the details of their existing products, such as price, quantity, or description.
  - Delete Product: Sellers can remove products from their inventory.
  
- Buyer Functions:
  - Browse Products: Buyers can browse and view the available products listed by sellers.
  - Add to Cart: Buyers can add products to their cart for purchase.
  - Purchase Products: Buyers can complete the purchase by confirming the items in their cart.

- Account Management:
  - Update Account Information: Sellers and buyers can update their account information, such as username, password, or contact details.

- Object-Oriented Concepts Used:
  - Inheritance: The project utilizes inheritance to create classes like Seller, Buyer, and Product, inheriting common attributes and methods from a base class User.
  - Polymorphism: Polymorphic functions are implemented, allowing different implementations for the same functions based on the context of the object.
  - Operator Overloading and Overriding: Appropriate operator overloading and overriding techniques are used for classes like Product and User.
  - File Handling: The project utilizes file handling to store and retrieve data related to users, products, and accounts.
  - Vectors: Vectors are used to store and manage collections of products and user data efficiently.
  - Friend Classes and Functions: Friend classes and functions are utilized where needed to allow access to private data or functionality.
