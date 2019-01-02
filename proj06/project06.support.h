
#define INFINITY  (__builtin_inf())
#define NAN       (__builtin_nan(""))

union double_precision
{
  double drep;
  unsigned long long int irep;
};

double add( double, double );

