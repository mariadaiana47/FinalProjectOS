# FinalProjectOS

Acesta este un proiect pentru cursul de **Sisteme de Operare**, realizat în cadrul programului de licență la **Computer Science**, anul II. Proiectul implementează un **manager de fișiere** în limbajul C, utilizând funcționalități precum listarea fișierelor, crearea și ștergerea acestora.

## **Funcționalități implementate**

1. **Listarea fișierelor** dintr-un director specificat de utilizator.
2. **Crearea fișierelor** în directorul specificat (cu extensia `.txt`).
3. **Ștergerea fișierelor** din directorul specificat.
4. Validarea existenței directorului înainte de procesare.
5. Funcționalități de curățare a inputului (eliminarea spațiilor, gestionarea căilor de director).

---

## **Tehnologii utilizate**

- **Limbajul C**: Toate funcționalitățile sunt implementate folosind standardul C.
- **Header-uri incluse**:
  - `stdio.h`, `stdlib.h`, `string.h`: Operații de bază pentru fișiere și string-uri.
  - `io.h`: Funcționalități pentru verificarea existenței fișierelor și directoarelor.
  - `dirent.h`: Funcționalități pentru crearea directoarelor.
  - `conio.h`: Curățarea ecranului.

---

## **Structura proiectului**

### **Fișierul `dirent.h`**
Pentru a permite o funcționalitate extinsă de navigare în directoare pe sisteme Windows, am integrat o versiune compatibilă cu Windows a fișierului POSIX `dirent.h`. Aceasta oferă:
- Funcții precum `opendir`, `readdir`, `closedir` pentru gestionarea directoarelor.
- Este folosit pentru **listarea fișierelor** dintr-un director specificat.

### **Funcțiile principale**
#### 1. `listFiles`
- Primește un director ca parametru și afișează toate fișierele din acesta.
- Folosește `_findfirst` și `_findnext` pentru a accesa fișierele.

#### 2. `createFile`
- Creează un fișier nou în directorul specificat.
- Adaugă automat extensia `.txt` la fișiere.
- Construiește calea completă pentru fișier înainte de creare.

#### 3. `deleteFile`
- Șterge un fișier specificat de utilizator.
- Verifică dacă fișierul există înainte de a încerca să-l șteargă.

#### 4. `trimSpaces`
- Elimină spațiile de la începutul și sfârșitul unei căi introduse de utilizator.

#### 5. `directoryExists`
- Verifică dacă un director specificat există folosind `_access`.

#### 6. `get_path`
- Formatează calea unui director pentru a se asigura că este validă și accesibilă.

---
