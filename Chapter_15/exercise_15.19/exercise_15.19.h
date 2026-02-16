// Legal.
class Base
{
	void memfcn(Base &b) { b = *this; }
public:
	void pub_mem(); // public member
protected:
	int prot_mem;

private:
	char priv_mem;
};

// Extra class:
class Prot_Derv : protected Base {
	
};

// Legal. Only copies Base part of *this into b.
class Sneaky : public Base
{
	void memfcn(Base &b) { b = *this; }
	friend void clobber(Sneaky &); // canaccess Sneaky::prot_mem
	friend void clobber(Base &);
	int j;
};

// Legal.
struct Pub_Derv : public Base {
	void memfcn(Base &b) { b = *this; }
 // ok:derived classes can access protected members
 int f() { return prot_mem; }
 // error: private members are inaccessible to derived classes
// char g() { return priv_mem; }
 };

 // Legal.
  struct Priv_Derv : private Base {
	void memfcn(Base &b) { b = *this; }
 // privatederivation doesn’t affect access in the derived class
 int f1() const { return prot_mem; }
 };

 // Legal for Prot_Derv as well.

 // Legal.
  struct Derived_from_Public : public Pub_Derv {
	void memfcn(Base &b) { b = *this; }
 // ok:Base::prot_memremains protectedin Pub_Derv
 int use_base() { return prot_mem; }
 };

 // Illegal.
 struct Derived_from_Private : public Priv_Derv {
/*void memfcn(Base &b) { b = *this; }*/
 // error: Base::prot_mem s private in Priv_Derv
//  int use_base() { return prot_mem; }
 };

// Legal.
 struct Derived_from_Prot : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }
 };
 
// Legal.
 struct Derived_from_Prot2 : private Prot_Derv {
	void memfcn(Base &b) { b = *this; }
 // error: Base::prot_memis privatein Priv_Derv
//  int use_base() { return prot_mem; }
 };