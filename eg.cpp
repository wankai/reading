class Singleton
{
 public:
  static Singleton* instance()
  {
    if (!inited_)
    {
      MutexGuard mg(mutex_);
      if (!inited_)
      {
        new (&obj) Singleton;
        inited_ = true;
      }
    }
    return &obj_;
  }
  
 private:
  // disable constructing and copy
  
  static Mutex mutex_;
  static Singleton obj_;
  static bool inited_;
};
// initialize static member object
