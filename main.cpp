#define __SHOW__
#define __DBG__
#include "ysvb_bug_proof.hpp"

#include <gmpxx.h>
#include "matrix.hpp"
#include "integer_mod_p.hpp"
#include "polynomial.hpp"
#include <iostream>


typedef mpz_class long_int;
typedef ModInteger<long_int> ZP;
typedef MatrixNxN<ZP, 4> MNxN;


int main() { 
    int array[4] = {1,2,3,4};
    int arrayy[4] = {1,1,2,3};
    ModPolynomial<ZP, 4> poly(array), poly2(arrayy);
	
	
	//~ M4x4 A(8964, 9648, 6489, 4896, true);
	//~ M4x4 E(1234, 2345, 3456, 4567, true);
	//~ ZP Adet = A.det();
	//~ ZP Edet = E.det();
	//~ ZP Edetinv = Edet.inv();
	//~ E = M4x4(E.get(0,0)*Edetinv*Adet, E.get(1,0)*Edetinv*Adet, E.get(0,1), E.get(1,1));
	//~ YSVB_CHECK_1(A.det(), ==, E.det(), "Made to be so.")
	//~ M4x4 ID(1, 0, 0, 1);
	//~ M4x4 A_inverse = A.inverse();
	//~ M4x4 A_inv_inv = A_inverse.inverse();
	//~ M4x4 F = A*E*A_inverse;
			//~ // Display inverse matrix
	//~ YSVB_CHECK_1(0, ==, 1, "test")
	//~ YSVB_CHECK_1(A, ==, A_inv_inv, "inverse of inverse")
	//~ YSVB_CHECK_1(A, ==, A*ID, "identity")
	//~ YSVB_CHECK_1(A, ==, ID*A, "identity")
	//~ YSVB_CHECK_1(E, ==, E*ID, "identity")
	//~ YSVB_CHECK_1(E, ==, ID*E, "identity")
	//~ YSVB_CHECK_1(ID*ZP(2), ==, M4x4(2, 0, 0, 2), "inverse")
	//~ YSVB_CHECK_1((ID*ZP(A.det()))*(A_inverse.det()), ==, ID, "inverse")
	//~ YSVB_CHECK_1(A*A_inverse, ==, ID, "inverse")
	//~ YSVB_CHECK_1(A_inverse*A, ==, ID, "inverse")
	//~ YSVB_CHECK_1(A_inverse*A*E*A_inverse*A, ==, E, "homomorphism")
	//~ YSVB_CHECK_1(A_inverse*F*A, ==, E, "homomorphism")
	//~ YSVB_CHECK_1(A_inverse*(F+F)*A, ==, E+E, "homomorphism")
	//~ YSVB_CHECK_1(A_inverse*(F*ZP(5))*A, ==, E*ZP(5), "homomorphism")
	//~ YSVB_CHECK_1(A_inverse*(F*F)*A, ==, E*E, "homomorphism")
	
	//~ int t = 1, kb = 1024*128;
	//~ YSVB_TIMED_SHOW(t)
	//~ YSVB_TIMED_SHOW(kb)
	//~ YSVB_TIMED_SHOW(A)
	//~ M4x4 Ae = A.encrypt(E);
	//~ YSVB_TIMED_SHOW(Ae)
	//~ M4x4 Aeh = Ae.hash(t, kb);
	//~ YSVB_TIMED_SHOW(Aeh)
	//~ M4x4 Aehd = Aeh.decrypt(E);
	//~ YSVB_TIMED_SHOW(Aehd)
	//~ M4x4 Ah = A.hash(t, kb);
	//~ YSVB_TIMED_SHOW(Ah)
	//~ YSVB_CHECK_1(Aehd, ==, Ah, "homomorphism")
	//~ M4x4 Eh = E.hash(t, kb);
	//~ YSVB_TIMED_SHOW(Eh)
	//~ YSVB_CHECK_1(A.det(), ==, E.det(), "Made to be so")
	//~ YSVB_CHECK_1(Ah.det(), !=, Eh.det(), "infinitesimal chance")
	//~ YSVB_CHECK_1(Ah*(A.inverse()), !=, Eh*(E.inverse()), "Actually good!")
	//~ YSVB_CHECK_1(A*(Ah.inverse()), !=, E*(Eh.inverse()), "Actually good!")
}
