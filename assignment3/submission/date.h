class Date {
  private:
	int month;
	int day;
	int year;

	// These don't really need to be private functions but I think it's an
	// assignment requirement so I'm not going to touch it
	int getDaysInMonth() const;
	bool isLeapYear() const;
	bool isValid() const;
	int sakamoto(int m, int d, int y) const;

  public:
	Date();
	Date(int m, int d, int y);
	Date(const char *str);

	void Input();
	int GetMonth() const;
	int GetDay() const;
	int GetYear() const;
	bool Set(int m, int d, int y);
	void Increment();
	void Decrement();
	int DayofWeek() const;
	int Compare(const Date &d) const;
	void ShowByDay() const;
	void ShowByMonth() const;
};
