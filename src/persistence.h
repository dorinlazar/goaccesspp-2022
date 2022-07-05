#pragma once

class Persistence {
public:
  void Store();
  void Restore();
};

void restore_data(void);
void persist_data(void);
void free_persisted_data(void);
