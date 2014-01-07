
.. role:: texmath(raw)
  :format: latex html

Recursive Polynomial PDF Computation Package
============================================

For RooFit.

Info from Wikipedia below.

Laguerre
--------

Recurrance Relation
  L_0 = 1
  L_1 = 1-x
  L_{k+1} = \frac{1}{k+1} ((2k+1-x)L_k-kL_{k-1} )

L_n has n real roots in the interval (0,n+(n-1)\sqrt{n}]

Chebyshev
---------

Recurrance Relation
  T_0 = 1
  T_1 = x
  T_{k+1} = 2xT_k - T_{k-1}

:Domain: [-1,1]

Lagendre
--------

Recurrance Relation
  P_0 = 1
  P_1 = x
  (k+1) P_{k+1} = (2k + 1)xT_k - kT_{k-1}

:Domain: [-1,1]

Testing latex math :texmath:`$L_0 = \Sigma \approx ! \mu \sigma \psi$`
:texmath:`$$L_1 = T_1 + P_{k+1}$$`
