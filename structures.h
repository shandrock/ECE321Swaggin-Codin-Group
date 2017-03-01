#ifndef STRUCTURES_H_
define STRUCTURES_H_

struct student {
  char ID[16];
  char password[32];
  char firstName[16];
  char lastName[16];
};

struct faculty {
  char ID[16];
  char password[32];
  char firstName[16];
  char lastName[16];
};

struct class {
  char title[32];
};

struct vacancy {
  char position[32];
  char discription[128];
};

#endif // STRUCTURES_H_
