template <class T>
class Arbol {
protected:
  Nodo<T>* raiz;
public:
  Arbol();
  Arbol(T& val);
  ~Arbol();
  bool esVacio();
  Nodo<T>* obtenerRaiz();
  void fijarRaiz(Nodo<T>* nraiz);
  bool insertarNodo(T& padre, T& n);
  bool eliminarNodo(T& n);
  TAD Árbol
  bool buscar(T& n);
  unsigned int altura(Nodo<T>* inicio);
  unsigned int tamano(Nodo<T>* inicio);
  void inOrden(Nodo<T>* inicio);
  void preOrden(Nodo<T>* inicio);
  void posOrden(Nodo<T>* inicio);
  void nivelOrden(Nodo<T>* inicio);
};
