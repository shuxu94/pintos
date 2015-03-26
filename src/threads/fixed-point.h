#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define Q 14
#define F (1 << Q)

typedef int real;

static real fixed_point_create (int num, int denom);
static real fixed_point_multiply (real x, real y);
static real fixed_point_divide (real x, real y);
static int fixed_point_round_down (real x);
static int fixed_point_round_nearest (real x);


static real
fixed_point_create (int num, int denom)
{
  return (num * F) / denom;
}

static real
fixed_point_multiply (real x, real y)
{
  return ((int64_t)x) * y / F;
}


static real
fixed_point_divide (real x, real y)
{
  return ((int64_t)x) * F / y;
}

static int
fixed_point_round_down (real x)
{
  return x / F;
}

static int
fixed_point_round_nearest (real x)
{
  return (x >= 0) ? (x + F/2) / F : (x - F/2) / F;
}

#endif