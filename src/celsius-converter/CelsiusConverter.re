// convert Celsius to Fahrenheit
let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;

let getValueFromEvent = (evt): string => ReactEvent.Form.target(evt)##value;

let floatFromString = text => {
  let value = Js.Float.fromString(text);
  value->Js.Float.isNaN ? None : Some(value);
};

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");

  <div>
    <input
      value=celsius
      onChange={evt => {
        let value = getValueFromEvent(evt);
        setCelsius(_ => value);
      }}
    />
    {React.string({js|°C = |js})}
    {(
       if (celsius->String.trim == "") {
         {js|?°F|js};
       } else {
         switch (celsius |> floatFromString |> Option.map(convert)) {
         | None => "error"
         | Some(f) when f > 212.0 => {js|Unreasonably hot 🥵|js}
         | Some(f) when f < (-128.6) => {js|Unreasonably cold 🥶|js}
         | Some(f) =>
           f->Js.Float.toFixedWithPrecision(~digits=2) ++ {js|°F|js}
         };
       }
     )
     |> React.string}
  </div>;
};
