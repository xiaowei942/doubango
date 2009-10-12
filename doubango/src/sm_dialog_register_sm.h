#ifndef _H_SM_DIALOG_REGISTER_SM
#define _H_SM_DIALOG_REGISTER_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : sm_dialog_register.sm
 */


#define SMC_USES_IOSTREAMS

#define SMC_NO_EXCEPTIONS

#include <statemap.h>

namespace dgo
{
    // Forward declarations.
    class map_dialog_register;
    class map_dialog_register_Initialized;
    class map_dialog_register_Trying;
    class map_dialog_register_Established;
    class map_dialog_register_Authentifying;
    class map_dialog_register_Terminated;
    class map_dialog_register_Default;
    class sip_dialog_registerState;
    class sip_dialog_registerContext;
    class sip_dialog_register;

    class sip_dialog_registerState :
        public statemap::State
    {
    public:

        sip_dialog_registerState(const char *name, int stateId)
        : statemap::State(name, stateId)
        {};

        virtual void Entry(sip_dialog_registerContext&) {};
        virtual void Exit(sip_dialog_registerContext&) {};

        virtual void sm_1xx_response(sip_dialog_registerContext& context);
        virtual void sm_2xx_response(sip_dialog_registerContext& context);
        virtual void sm_401_407_421_494_response(sip_dialog_registerContext& context);
        virtual void sm_registerSent(sip_dialog_registerContext& context);
        virtual void sm_unregisterSent(sip_dialog_registerContext& context);
        virtual void sm_unsupported_response(sip_dialog_registerContext& context);

    protected:

        virtual void Default(sip_dialog_registerContext& context);
    };

    class map_dialog_register
    {
    public:

        static map_dialog_register_Initialized Initialized;
        static map_dialog_register_Trying Trying;
        static map_dialog_register_Established Established;
        static map_dialog_register_Authentifying Authentifying;
        static map_dialog_register_Terminated Terminated;
    };

    class map_dialog_register_Default :
        public sip_dialog_registerState
    {
    public:

        map_dialog_register_Default(const char *name, int stateId)
        : sip_dialog_registerState(name, stateId)
        {};

        virtual void sm_401_407_421_494_response(sip_dialog_registerContext& context);
        virtual void Default(sip_dialog_registerContext& context);
    };

    class map_dialog_register_Initialized :
        public map_dialog_register_Default
    {
    public:
        map_dialog_register_Initialized(const char *name, int stateId)
        : map_dialog_register_Default(name, stateId)
        {};

        void Entry(sip_dialog_registerContext&);
        void sm_registerSent(sip_dialog_registerContext& context);
    };

    class map_dialog_register_Trying :
        public map_dialog_register_Default
    {
    public:
        map_dialog_register_Trying(const char *name, int stateId)
        : map_dialog_register_Default(name, stateId)
        {};

        void Entry(sip_dialog_registerContext&);
        void sm_1xx_response(sip_dialog_registerContext& context);
        void sm_2xx_response(sip_dialog_registerContext& context);
        void sm_401_407_421_494_response(sip_dialog_registerContext& context);
        void sm_unsupported_response(sip_dialog_registerContext& context);
    };

    class map_dialog_register_Established :
        public map_dialog_register_Default
    {
    public:
        map_dialog_register_Established(const char *name, int stateId)
        : map_dialog_register_Default(name, stateId)
        {};

        void Entry(sip_dialog_registerContext&);
        void sm_unregisterSent(sip_dialog_registerContext& context);
    };

    class map_dialog_register_Authentifying :
        public map_dialog_register_Default
    {
    public:
        map_dialog_register_Authentifying(const char *name, int stateId)
        : map_dialog_register_Default(name, stateId)
        {};

        void Entry(sip_dialog_registerContext&);
    };

    class map_dialog_register_Terminated :
        public map_dialog_register_Default
    {
    public:
        map_dialog_register_Terminated(const char *name, int stateId)
        : map_dialog_register_Default(name, stateId)
        {};

        void Entry(sip_dialog_registerContext&);
        void Default(sip_dialog_registerContext& context);
    };

    class sip_dialog_registerContext :
        public statemap::FSMContext
    {
    public:

        sip_dialog_registerContext(sip_dialog_register& owner)
        : FSMContext(map_dialog_register::Initialized),
          _owner(owner)
        {};

        sip_dialog_registerContext(sip_dialog_register& owner, const statemap::State& state)
        : FSMContext(state),
          _owner(owner)
        {};

        virtual void enterStartState()
        {
            getState().Entry(*this);
            return;
        }

        sip_dialog_register& getOwner() const
        {
            return (_owner);
        };

        sip_dialog_registerState& getState() const
        {
            if (_state == NULL)
            {
                assert(1 == 0);
            }

            return (dynamic_cast<sip_dialog_registerState&>(*_state));
        };

        void sm_1xx_response()
        {
            (getState()).sm_1xx_response(*this);
        };

        void sm_2xx_response()
        {
            (getState()).sm_2xx_response(*this);
        };

        void sm_401_407_421_494_response()
        {
            (getState()).sm_401_407_421_494_response(*this);
        };

        void sm_registerSent()
        {
            (getState()).sm_registerSent(*this);
        };

        void sm_unregisterSent()
        {
            (getState()).sm_unregisterSent(*this);
        };

        void sm_unsupported_response()
        {
            (getState()).sm_unsupported_response(*this);
        };

    private:

        sip_dialog_register& _owner;
    };
}


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_SM_DIALOG_REGISTER_SM
