// gcd(a, b) is the greatest common divisor of a and b
long long gcd(long long a, long long b)
{
  return (b == 0 ? a : gcd(b, a % b));
}

// lcm(a, b) is the largest common multiple of a and b
long long lcm(long a, long long b)
{
  return ((a * b) / gcd(a, b));
}

/*
Explaination:
  Accoding to the euclidian algorithm:
  1. If a = 0 then gcd(a, b) = b
  2. If b = 0 then gcd(a, b) = a
  3. gcd(a, b) = gcd(b, r) where r is a%b
     because a = b⋅q + r where q is the quotient
  4. We know that a*b = gcd(a, b) * lcm(a, b), so
     lcm(a, b) = (a * b) / gcd(a, b)

Usage:
  gcd(5, 20)  -> 5
  lcm(2, 8)   -> 8
  etc..

  example: https://ideone.com/A0J54Y
*/
