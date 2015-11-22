class Singleton
{
 public:
  static Singleton* instance()
  {
    Singleton* tmp = interpret_cast<Singleton*>(ptr_.load(std::memory_order_acquire));
    if (tmp == NULL) {
      {
        MutexGuard mg(mutex_);
        if (ptr_ == NULL) {
          Singleton* t = new Singleton;
          ptr_.store(t, std::memory_order_release);
        }
      }
      local_ptr_ = ptr_;
    }
    return tmp;
  }
  
 private:
  Singleton();
  static Mutex mutex_;
  static std::atomic<uintptr_t> ptr_;
};
