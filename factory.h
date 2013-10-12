//---------------------------------------------------------------------------
#ifndef factoryH
#define factoryH
//---------------------------------------------------------------------------
namespace DarkPath
{
    template <
        typename K, typename T,
        template <typename> typename copy_policy
    >
    class Factory;

    template <
        typename K, typename T,
        template <typename> typename copy_policy
    >
    class FactoryRegister
    {
        public:
            typedef Factory<K, T, copy_policy> ParentFactory;
        public:
            FactoryRegister(K key, T val, ParentFactory& factory)
            {
                factory.Register(key, val);
            }
    };

    template <
        typename K, typename T,
        template <typename> typename copy_policy
    >
    class Factory
    {
        public:
            typedef K               key_type;
            typedef T               value_type;
            typedef copy_policy<T>  CopyPolicy;
        private:
            std::map<K, T>  map_Objects;
        public:
            void Register(K key, T val)
            {
                std::pair<std::map<K, T>::iterator, bool>
                    p = map_Objects.insert(key, val);

                if (!p.second)
                {
                    throw 1; //!!!!!!!!!!!!!
                }
            }

            T Get(const K key) const
            {
                std::map<K, T>::iterator i = map_Objects.find(key);

                if (i == map_Objects.end())
                {
                    throw 1; //!!!!!!!!!!
                }

                std::pair<const K, T>& p = *i;

                return CopyPolicy::copy(p.second);
            }
    };
}
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
