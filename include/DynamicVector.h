#ifndef _DYNAMICVECTOR_H_
#define _DYNAMICVECTOR_H_

#include "Common.h"

/*! \brief A variable-size vector for aritmetic operations.
 *  \tparam T Main data type of the values.
 */
template<typename T>
class DynamicVector
{
public:
    /*! \brief Constructor.
     *
     *  \param size The size of the vector (dimensions).
     */
    DynamicVector(unsigned int size = 0);

    /*! \brief Virtual destructor.
     */
    virtual ~DynamicVector();
    
    /*! \brief Copy assignment operator.
     *
     *  Copies all elements.
     */
    DynamicVector& operator= (const DynamicVector& other);

    /*! \brief Resizes the vector and initializes new values to
     *         a default value.
     *
     *  \param size The size of the vector (dimensions).
     *  \param value The default value.
     */
    void Resize(unsigned int size, T value = T());

    /*! \brief Returns the size of the vector (dimension count).
     *
     *  \return The size of the vector (dimension count).
     */
    unsigned int GetSize() const;

    /*! \brief Adds a new value and increases the size of
     *         the vector by one.
     *
     *  \param value The value to be added.
     */
    void Push(T value);

    /*! \brief Non-const access operator.
     */
    T& operator[] (unsigned int index);

    /*! \brief Const access operator.
     */
    const T& operator[] (unsigned int index) const;

    /*! \brief Assigns a given value to each dimension.
     *
     *  \param value The value to be assigned.
     */
    void Assign(T value);
    
    /*! \brief Multiplies every dimension value by a given multiplier.
     *
     *  \param value The multiplier.
     */
    void Multiply(T value);
    
    /*! \brief Multiplies by another vector dimension by dimension.
     *
     *  \param other The other vector.
     */
    void Multiply(const DynamicVector& other);

    /*! \brief Divides by another vector dimension by dimension.
     *
     *  \param other The other vector.
     */
    void Divide(const DynamicVector& other);

    /*! \brief Adds a given value to each dimension.
     *
     *  \param value The summand.
     */
    void Add(T value);

    /*! \brief Vector copying.
     *
     *  Copies and assigns values from another vector.
     *  
     *  \note Vector sizes must match.
     *
     *  \param other The other vector.
     */
    void Assign(const DynamicVector& other);

    /*! \brief Vector addition.
     *
     *  \param other The summand.
     */
    void Add(const DynamicVector& other);

    /*! \brief Vector subtraction.
     *
     *  \param other The subtrahend.
     */
    void Subtract(const DynamicVector& other);

    /*! \brief Calculates a squared euclidean distance to another vector.
     *
     *  \todo Change function name.
     *
     *  \param other The other vector.
     *  \return The squared euclidean distance.
     */
    T Distance(const DynamicVector& other) const;

private:
    std::vector<T> mValues;
};

#include "DynamicVector.inl"

#endif
