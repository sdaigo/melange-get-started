// convert Celsius to Fahrenheit
let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;

let getValueFromEvent = (evt): string => ReactEvent.Form.target(evt)##value;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");

  <div>
    <input
      value=celsius
      onChange={evt => {
        let x = getValueFromEvent(evt);
        setCelsius(_ => x);
      }}
    />
    {React.string({js|°C = |js})}
    {(
       if (celsius == "") {
         {js|?°F|js};
       } else {
         switch (
           celsius
           |> float_of_string
           |> convert
           |> Js.Float.toFixedWithPrecision(~digits=2)
         ) {
         | exception _ => "error"
         | f => f ++ {js|°F|js}
         };
       }
     )
     |> React.string}
  </div>;
};
