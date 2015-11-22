class Singleton
{
 public:
  static Singleton* instance()
  {
    Singleton* tmp = ptr_.load(std::memory_order_acquire));
    if (tmp == NULL) {
      {
        MutexGuard mg(mutex_);
        if (ptr_ == NULL) {
          tmp = new Singleton;
          ptr_.store(tmp, std::memory_order_release);
        }
      }
      local_ptr_ = ptr_;
    }
    return tmp;
  }
  
 private:
  Singleton();
  static Mutex mutex_;
  static AtomicPtr<Singleton> ptr_;
};
