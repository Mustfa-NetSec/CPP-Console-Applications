# C++ Console Applications & Games

Welcome to my repository dedicated to C++ Console Applications. This space showcases a collection of command-line tools, utilities, and interactive games built to practice and master core programming concepts, clean code structures, and logical problem-solving.

---

## Projects Included

### 1. Stone, Paper, Scissors Game
An interactive, terminal-based classic game played against the computer. This project focuses on structural organization, user-input handling, and implementing game-state logic.

**Key Technical Concepts Implemented:**
* **Data Structuring:** Utilized Enums and Structs for elegant state management and clear game configurations.
* **Control Flow & Arrays:** Managed game rounds, scoring, and data retrieval using arrays and custom loops.
* **Randomization:** Used smart pseudo-random number generation to simulate competitive computer moves.
* **Input Validation:** Built robust error-handling to ensure a smooth and crash-free user experience in the console.

### 2. Simple Text Encryptor
A security-focused C++ Console Application that implements text encryption and decryption using the classic Caesar Cipher algorithm. This utility demonstrates fundamental cryptographic practices, data handling, and character-level encoding.

**Key Technical Concepts Implemented:**
* **Cryptographic Logic:** Applied predictable ASCII character shifting to transform plaintext into secure ciphertext and back.
* **String Manipulation:** Advanced handling of text inputs, loop iterations over strings, and inline character conversions.
* **Function Modularity:** Formatted with clear, single-responsibility functions for reading text, encrypting, and decrypting to maintain high code readability.
* **User Interactive Flow:** Designed a seamless console interface guiding users through sample input, cipher shifts, and automated real-time verification.

### 3. Cryptographic Key Generator
An automated serial key generation utility that creates secure, cryptographic-style validation keys formatted in blocks (e.g., XXXX-XXXX-XXXX-XXXX). This project emphasizes algorithmic logic, formatting, and randomized token simulation.

**Key Technical Concepts Implemented:**
* **Custom Character Seeding:** Implemented a robust enCharType abstraction to dynamically switch between character subsets (capital letters, digits, etc.).
* **Randomization Controls:** Integrated custom bounds-driven random number generation to safely query raw ASCII decimal ranges.
* **Token Formatting & String Appending:** Managed sequence loops to dynamically assemble standard authorization blocks interspersed with hyphens.
* **Modular Input Streams:** Designed validation functions to ensure target iteration counts are positive, avoiding infinite loops during console execution.

### 4. Interactive Math Game
A dynamic quiz-style math game that challenges users with custom operations and randomized numbers. This application features flexible query logic, comprehensive custom statistics tracking, and dynamic problem generation based on user preferences.

**Key Technical Concepts Implemented:**
* **Nested Custom Structs:** Created complex structural arrays (stQuizz and stQuestion) to accurately store runtime game states and individual question results.
* **Algorithmic Math Evaluation:** Built robust evaluation logic parsing multiple distinct standard operations (Addition, Subtraction, Multiplication, Division).
* **Dynamic Difficulty Adjustments:** Implemented strict range-bounding controls to generate distinct numeric tiers mapped directly to user-selected difficulty ranks.
* **Scorekeeping & Reporting:** Engineered clear reporting pipelines that accurately summarize right and wrong answer aggregates to compute passing results.

---

##  Setup and How To Run

### Prerequisites
* **IDE:** Visual Studio (2022 recommended)
* **Compiler:** Standard C++ Compiler (supporting C++17 or newer)
