#ifndef FILE_MYHOELEMENT_HPP
#define FILE_MYHOELEMENT_HPP

/*********************************************************************/
/* File:   myHOElement.hpp                                           */
/* Author: Joachim Schoeberl                                         */
/* Date:   26. Apr. 2009                                             */
/*********************************************************************/

/*
  
It is also simple to implement high order elements ...

*/


namespace ngfem
{


  /*
    A Segment finite element with arbitrary order hierarchic basis
    functions
   */
  class MyHighOrderSegm : public ScalarFiniteElement<1>, public VertexOrientedFE<ET_SEGM>
  {
  public:
    MyHighOrderSegm (int order);
    virtual ELEMENT_TYPE ElementType() const { return ET_SEGM; }

    virtual void CalcShape (const IntegrationPoint & ip, 
                            BareSliceVector<> shape) const;
  
    virtual void CalcDShape (const IntegrationPoint & ip, 
                             BareSliceMatrix<> dshape) const;

  private:
    template <class T>
    void T_CalcShape (T x, BareSliceVector<T> shape) const;
  };


  /*
    A triangular finite element with arbitrary order hierarchic basis
    functions
   */
  class MyHighOrderTrig : public ScalarFiniteElement<2>, public VertexOrientedFE<ET_TRIG>
  {
  public:
    MyHighOrderTrig (int order);
    virtual ELEMENT_TYPE ElementType() const { return ET_TRIG; }

    virtual void CalcShape (const IntegrationPoint & ip, 
                            BareSliceVector<> shape) const;
  
    virtual void CalcDShape (const IntegrationPoint & ip, 
                             BareSliceMatrix<> dshape) const;

  private:
    template <class T>
    void T_CalcShape (const T & x, const T & y, BareSliceVector<T> shape) const;
  };
}

#endif

