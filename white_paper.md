# Finite Field Matrix (FFM) Cryptosystem - White Paper

We present a public-key cryptosystem based on the difficulties of polynomial factorization on finite fields as well as that of finding n-th roots. Our proposed cryptosystem admits both a signature and a encryption scheme. The possibility of secret a sharing scheme is still an open question.

## The Keys

**Public Key** consists of an **nxn** full-rank matrix **B** over a finite field of known, brute-force-resistant order **p**.

**Private Key** consists of **B** and its eigenvalue decomposition, say, **k_1**, ..., **k_n**, the eigenvalues, and **r_1**, ..., **r_n**, the eigenvectors.

**Deciphering the Private Key**, therefore, consists of finding eigenvalue decomposition of **B** by factorizing its characteristic polynomial.

**Keys Generation** is done by uniformly randomly selecting **n** non-zero elements of **F_p** as **k_i**'s, and one invertible **nxn** matrix **R** over the same field, then finding its inverse **R^(-1)** and calculating **B = R*A*R^(-1)** where, **A** is the diagonal matrix having the **k_i**'s as non-zero entries.

## Signature Scheme

In order to **sign** (the mapping of the hash of a document into) an element **d** of **F_p**, Alice, the owner of **A**, calculates a **m**-degree polynomial **s** over **F_p**, given by the product of binomials **(x-(k_i)^d)**'s for **m ~ n/2** different **i**'s. Additionally, **(m, n)** have to satisfy **1 < m < n-1**, hence why we have **n > 3**.

In order to **verify** the signing above by Alice, Bob, the verifier, checks whether **s | det(B^d-xI)**, that is, whether Alice's signature divides the characteristic polynomial of her public key elevated to the signed document. Signature is deemed valid if and only if divisibility is true.

**Deciphering the Private Key from a signature**, therefore, consists of factorizing **s** and **det(B^d-xI) / s**.

**Forging a signature** without the private key, therefore, would require finding an **m**-degree factor of **det(B^d-xI)**.

## Encryption Scheme

In order to **encrypt** (the mapping of a plaintext into) an element **P** of the set of (full-rank) **nxn** matrices over **F_p**, sender Bob, user of B, calculates **C = P*B*P^(-1)**.

In order to **decrypt** the ciphertext **C**, Alice solves **(C-k_iI)v_i = 0** to find all eigenvectors **v_i** of **C**, then computes **P = [v_1, ..., v_n]*R^(-1)**.

## About the author

[Yuri S Villas Boas](https://linktr.ee/yurisvb)
