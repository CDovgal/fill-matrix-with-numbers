#ifdef TESTLIB_EXPORTS
#define TESTLIB_API __declspec(dllexport)
#else
#define TESTLIB_API __declspec(dllimport)
#endif


class TESTLIB_API BaseFactory
{
public:
  virtual ~BaseFactory(){};
  //virtual BaseInput* createInput() = 0;
  //virtual BaseOutput* createOutput() = 0;
  virtual void STUB() = 0;

};

class TESTLIB_API AliveFactory : public BaseFactory
{
public:
  AliveFactory(){}
  virtual void STUB();
  /*BaseInput* createInput()
  {
  return new AliveInput();
  }
  BaseOutput* createOutput()
  {
  return new AliveOutput();
  }*/
};

extern "C" TESTLIB_API BaseFactory* getFactory();


